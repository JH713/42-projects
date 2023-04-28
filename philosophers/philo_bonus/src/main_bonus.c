/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:52:34 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/28 23:41:29 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_args	check_and_store_args(int ac, char *av[])
{
	t_args	args;

	if (ac != 5 && ac != 6)
		print_error("Please input 4 to 5 arguments.");
	args.phil_num = check_and_get_int(av[1]);
	args.die_ms = check_and_get_int(av[2]);
	args.eat_ms = check_and_get_int(av[3]);
	args.sleep_ms = check_and_get_int(av[4]);
	if (ac == 6)
		args.meal_cnt = check_and_get_int(av[5]);
	else
		args.meal_cnt = -1;
	return (args);
}

void	wait_all_child(pid_t *pid, int phil_num)
{
	int	i;
	int	status;

	i = 0;
	while (i < phil_num)
	{
		waitpid(pid[i], &status, 0);
		++i;
	}
}

int	get_passed_time_ms(t_info *info, enum e_state state)
{
	struct timeval	start;
	struct timeval	now;
	long long		passed_time;

	start = info->start;
	gettimeofday(&now, NULL);
	if (state == EAT)
		info->last_meal = now;
	passed_time = (now.tv_sec - start.tv_sec) * 1000 \
	+ (now.tv_usec - start.tv_usec) / 1000;
	return ((int) passed_time);
}

void	print_msg(t_info *info, int id, t_state state)
{
	int	passed_time;

	sem_wait(info->sem_msg);
	passed_time = get_passed_time_ms(info, state);
	if (state == FORK)
		printf("%d %d has taken a fork\n", passed_time, id);
	else if (state == EAT)
	{
		printf("%d %d is eating\n", passed_time, id);
		if (info->args->meal_cnt > 0)
			info->args->meal_cnt--;
		if (info->args->meal_cnt == 0)
			sem_post(info->sem_die);
	}
	else if (state == SLEEP)
		printf("%d %d is sleeping\n", passed_time, id);
	else if (state == THINK)
		printf("%d %d is thinking\n", passed_time, id);
	else if (state == DIED)
	{
		printf("%d %d died\n", passed_time, id);
		return ;
	}
	sem_post(info->sem_msg);
}

static void	sleep_func(int time_ms)
{
	struct timeval	start;
	struct timeval	now;
	struct timeval	target;

	gettimeofday(&start, NULL);
	target.tv_usec = start.tv_usec + (time_ms % 1000) * 1000;
	target.tv_sec = start.tv_sec + time_ms / 1000 + target.tv_usec / 1000000;
	target.tv_usec %= 1000000;
	gettimeofday(&now, NULL);
	while (now.tv_sec < target.tv_sec || now.tv_usec < target.tv_usec)
	{
		gettimeofday(&now, NULL);
		usleep(100);
	}
	return ;
}

void	*monitor_func(void *arg)
{
	t_info			*info;
	struct timeval	now;
	int				time_spent;
	int				i;

	info = (t_info *)arg;
	while (1)
	{
		usleep(100);
		gettimeofday(&now, NULL);
		time_spent = (now.tv_sec - info->last_meal.tv_sec) * 1000 \
		+ (now.tv_usec - info->last_meal.tv_usec) / 1000;
		if (time_spent >= info->args->die_ms)
		{
			print_msg(info, info->id, DIED);
			i = 0;
			while (i < info->args->phil_num)
			{
				sem_post(info->sem_die);
				++i;
			}
			break ;
		}
	}
	return (NULL);
}

void	kill_processes(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->args->phil_num)
	{
		sem_wait(info->sem_die);
		++i;
	}
	i = 0;
	while (i < info->args->phil_num)
	{
		kill(info->pid[i], SIGKILL);
		++i;
	}
}

int	main(int ac, char **av)
{
	t_args			args;
	t_info			info;
	int				i;
	pthread_t		monitoring;

	args = check_and_store_args(ac, av);
	info.args = &args;
	open_sems(&info);
	info.pid = (pid_t *)malloc(sizeof(pid_t) * args.phil_num);
	if (info.pid == NULL)
		print_perror("pid malloc");
	i = 0;
	gettimeofday(&info.start, NULL);
	info.last_meal = info.start;
	while (i < args.phil_num)
	{
		info.pid[i] = fork();
		if (info.pid[i] == -1)
			print_perror("fork");
		if (info.pid[i] == 0)
		{
			info.id = i + 1;
			if (pthread_create(&monitoring, NULL, monitor_func, &info) != 0)
				print_perror("pthread_create");
			while (1)
			{
				sem_wait(info.sem_fork);
				print_msg(&info, i + 1, FORK);
				sem_wait(info.sem_fork);
				print_msg(&info, i + 1, FORK);
				print_msg(&info, i + 1, EAT);
				sleep_func(args.eat_ms);
				sem_post(info.sem_fork);
				sem_post(info.sem_fork);
				print_msg(&info, i + 1, SLEEP);
				sleep_func(args.sleep_ms);
				print_msg(&info, i + 1, THINK);
				sleep_func(2);
			}
			pthread_join(monitoring, NULL);
		}
		++i;
	}
	kill_processes(&info);
	wait_all_child(info.pid, args.phil_num);
	close_and_unlink_sems(&info);
	free(info.pid);
}
