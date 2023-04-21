/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:01:03 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/21 23:32:03 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (*(s + cnt))
		cnt++;
	return (cnt);
}	

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	check_num(char *num)
{
	while (*num)
	{
		if (!ft_isdigit(*num))
			return (0);
		num++;
	}
	return (1);
}

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}

void	print_perror(char *msg)
{
	perror(msg);
	exit(1);
}

void	print_error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(1);
}

static int	ft_isblank(char c)
{
	if (c == ' ' || c == '\t' || c == '\v')
		return (1);
	else if (c == '\f' || c == '\n' || c == '\r')
		return (1);
	else
		return (0);
}

t_info	*get_info(t_args *args, pthread_mutex_t *fork, pthread_mutex_t *msg)
{
	struct timeval	start;
	t_info			*info;
	int				i;

	gettimeofday(&start, NULL);
	args->fork = fork;
	args->msg = msg;
	args->start = start;
	args->last_meal = start;
	args->died = 0;
	args->fork_available = (int *)malloc(sizeof(int) * args->phil_num);
	memset(args->fork_available, 0, args->phil_num * sizeof(int));
	info = (t_info *)malloc(sizeof(t_info) * args->phil_num);
	if (info == NULL)
		print_perror("malloc");
	i = 0;
	while (i < args->phil_num)
	{
		info[i].id = i + 1;
		info[i].args = args;
		++i;
	}
	return (info);
}

int	ft_atoi(const char *str)
{
	long long	result;
	int			is_positive;

	result = 0;
	is_positive = 1;
	while (ft_isblank(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		is_positive = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * is_positive);
}

int	is_positive_int(char *num)
{
	if (ft_strlen(num) > 10 || !check_num(num))
		return (0);
	if (ft_strlen(num) == 10)
	{
		if (*num != '1' && *num != '2')
			return (0);
		if (ft_atoi(num) < 0)
			return (0);
	}
	if (ft_atoi(num) == 0)
		return (0);
	return (1);
}

int	check_and_get_int(char *str)
{
	if (!is_positive_int(str))
		print_error("The arguments must be positive integers.");
	return (ft_atoi(str));
}

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
		args.meal_cnt = 0;
	return (args);
}

int get_passed_time_ms(t_info *info, enum e_state state)
{
	struct timeval	start;
	struct timeval	now;
	long long		passed_time;

	start = info->args->start;
	gettimeofday(&now, NULL);
	if (state == EAT)
		info->args->last_meal = now;
	passed_time = (now.tv_sec - start.tv_sec) * 1000 + (now.tv_usec - start.tv_usec) / 1000;
	return ((int) passed_time);
}

void	print_msg(t_info *info, enum e_state state)
{
	int	passed_time;

	if (info->args->died == 1)
		return ;
	pthread_mutex_lock(info->args->msg);
	passed_time = get_passed_time_ms(info, state);
	if (state == FORK)
		printf("%dms %d has taken fork\n", passed_time, info->id);
	else if (state == EAT)
		printf("%dms %d is eating\n", passed_time, info->id);
	else if (state == SLEEP)
		printf("%dms %d is sleeping\n", passed_time, info->id);
	else if (state == THINK)
		printf("%dms %d is thinking\n", passed_time, info->id);
	else if (state == DIED)
	{
		printf("%dms %d died\n", passed_time, info->id);
		pthread_mutex_unlock(info->args->msg);
		return ;
	}
	pthread_mutex_unlock(info->args->msg);
}

void	take_fork(pthread_mutex_t *fork, t_info *info)
{
	pthread_mutex_lock(fork);
	print_msg(info, FORK);
}

void	take_left_fork(t_info *info, int *flag)
{
	if (info->args->fork_available[info->id - 1] == 1)
	{
		if (info->id == info->args->phil_num)
			pthread_mutex_unlock(&(info->args->fork[0]));
		else
			pthread_mutex_unlock(&(info->args->fork[info->id]));
		return ;
	}
	info->args->fork_available[info->id - 1] = 1;
	take_fork(&(info->args->fork[info->id - 1]), info);
	*flag = 1;
}

void	take_right_fork(t_info *info)
{
	if (info->id == info->args->phil_num)
	{
		info->args->fork_available[0] = 1;
		take_fork(&(info->args->fork[0]), info);
	}
	else
	{
		info->args->fork_available[info->id] = 1;
		take_fork(&(info->args->fork[info->id]), info);
	}
}

void	put_back_both_forks(t_info *info)
{
	if (info->id == info->args->phil_num)
	{
		pthread_mutex_unlock(&(info->args->fork[0]));
		info->args->fork_available[0] = 0;
		pthread_mutex_unlock(&(info->args->fork[info->id - 1]));
		info->args->fork_available[info->id - 1] = 0;
	}
	else
	{
		pthread_mutex_unlock(&(info->args->fork[info->id]));
		info->args->fork_available[info->id] = 0;
		pthread_mutex_unlock(&(info->args->fork[info->id - 1]));
		info->args->fork_available[info->id - 1] = 0;
	}
}

void	*routine(void *arg)
{
	t_info	*info;
	int		flag;

	info = (t_info *)arg;
	if (info->id % 2 != 0)
		usleep(100);
	while (info->args->died != 1)
	{
		flag = 0;
		while (flag == 0)
		{
			if (info->args->fork_available[info->id - 1] == 0)
				take_right_fork(info);
			take_left_fork(info, &flag);
		}
		print_msg(info, EAT);
		usleep(info->args->eat_ms * 1000);
		put_back_both_forks(info);
		print_msg(info, SLEEP);
		usleep(info->args->sleep_ms);
		print_msg(info, THINK);
	}
	return (NULL);
}

void	create_threads(pthread_t **philo, t_info *info)
{
	int		i;
	int		phil_num;

	phil_num = info->args->phil_num;
	*philo = (pthread_t *)malloc(sizeof(pthread_t) * phil_num);
	if (*philo == NULL)
		print_perror("malloc");
	i = 0;
	while (i < phil_num)
	{
		if (pthread_create(&(*philo)[i], NULL, routine, (void *)&(info[i])) != 0)
			print_perror("pthread_create");
		++i;
	}
}

void	create_mutexs(pthread_mutex_t **fork, int phil_num, pthread_mutex_t *msg)
{
	int	i;

	*fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * phil_num);
	if (*fork == NULL)
		print_perror("malloc");
	i = 0;
	while (i < phil_num)
	{
		if (pthread_mutex_init(&(*fork)[i], NULL) != 0)
			print_perror("pthread_mutex_init");
		++i;
	}
	if (pthread_mutex_init(msg, NULL) != 0)
		print_perror("pthread_mutex_init");
}

void	destroy_mutexs(pthread_mutex_t **fork, int phil_num, pthread_mutex_t *msg)
{
	int	i;

	i = 0;
	while (i < phil_num)
	{
		if (pthread_mutex_destroy(&(*fork)[i]) != 0)
			print_perror("fork pthread_mutex_destroy");
		++i;
	}
	free(*fork);
	*fork = NULL;
	if (pthread_mutex_destroy(msg) != 0)
		print_perror("msg pthread_mutex_destroy");
}

int	main(int ac, char **av)
{
	t_args			args;
	pthread_t		*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	msg;
	int				i;
	struct timeval	now;
	int				time_spent;
	t_info			*info;

	args = check_and_store_args(ac, av);
	create_mutexs(&fork, args.phil_num, &msg);
	info = get_info(&args, fork, &msg);
	create_threads(&philo, info);
	while (args.died != 1)
	{
		usleep(100);
		i = 0;
		gettimeofday(&now, NULL);
		while (i < args.phil_num)
		{
			time_spent = (now.tv_sec - args.last_meal.tv_sec) * 1000 + (now.tv_usec - args.last_meal.tv_usec) / 1000;
			if (time_spent >= args.die_ms)
			{
				print_msg(&info[i], DIED);
				args.died = 1;
			}
			++i;
		}
	}
	i = 0;
	while (i < args.phil_num)
	{
		pthread_join(philo[i], NULL);
		++i;
	}
	destroy_mutexs(&fork, args.phil_num, &msg);
}
