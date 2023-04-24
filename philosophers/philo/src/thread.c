/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:06:41 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/24 20:08:46 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

static void	*routine(void *arg)
{
	t_info	*info;

	info = (t_info *)arg;
	if (info->id % 2 != 0)
		usleep(100);
	while (info->args->died != 1)
	{
		if (take_both_fork(info) == 0)
			break ;
		print_msg(info, EAT);
		sleep_func(info->args->eat_ms);
		put_back_both_forks(info);
		print_msg(info, SLEEP);
		sleep_func(info->args->sleep_ms);
		print_msg(info, THINK);
		sleep_func(1);
	}
	return (NULL);
}

void	create_threads(pthread_t **philo, t_info *info)
{
	int		i;
	int		error;
	int		phil_num;

	phil_num = info->args->phil_num;
	*philo = (pthread_t *)malloc(sizeof(pthread_t) * phil_num);
	if (*philo == NULL)
		print_perror("malloc");
	i = 0;
	while (i < phil_num)
	{
		error = pthread_create(&(*philo)[i], NULL, routine, (void *)&(info[i]));
		if (error != 0)
			print_perror("pthread_create");
		++i;
	}
}

void	join_threads(pthread_t *philo, t_args *args)
{
	int	i;

	i = 0;
	while (i < args->phil_num)
	{
		pthread_join(philo[i], NULL);
		++i;
	}
}
