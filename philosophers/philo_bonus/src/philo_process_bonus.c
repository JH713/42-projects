/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_process_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 23:53:49 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/29 16:12:45 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	print_msg(t_info *info, int id, t_state state)
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

static void	*monitor_func(void *arg)
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

static void	routine(t_info *info)
{
	sem_wait(info->sem_fork);
	print_msg(info, info->id, FORK);
	sem_wait(info->sem_fork);
	print_msg(info, info->id, FORK);
	print_msg(info, info->id, EAT);
	sleep_func(info->args->eat_ms);
	sem_post(info->sem_fork);
	sem_post(info->sem_fork);
	print_msg(info, info->id, SLEEP);
	sleep_func(info->args->sleep_ms);
	print_msg(info, info->id, THINK);
	sleep_func(1);
}

void	philo_process(t_info *info)
{
	int			i;
	pthread_t	monitoring;

	i = 0;
	while (i < info->args->phil_num)
	{
		info->pid[i] = fork();
		if (info->pid[i] == -1)
			print_perror("fork");
		if (info->pid[i] == 0)
		{
			info->id = i + 1;
			if (pthread_create(&monitoring, NULL, monitor_func, info) != 0)
				print_perror("pthread_create");
			while (1)
				routine(info);
			pthread_join(monitoring, NULL);
		}
		++i;
	}
}
