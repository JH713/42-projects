/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:06:41 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/30 22:43:17 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	sleep_func(t_info *info, int time_ms)
{
	struct timeval	start;
	struct timeval	now;
	struct timeval	target;
	// int				_kill;

	// pthread_mutex_lock(info->args->msg);
	// _kill = info->args->died;
	// pthread_mutex_unlock(info->args->msg);
	// if (_kill)
	// 	return ;
	if (info->args->died == 1)
		return ;
	gettimeofday(&start, NULL);
	target.tv_usec = start.tv_usec + (time_ms % 1000) * 1000;
	target.tv_sec = start.tv_sec + time_ms / 1000 + target.tv_usec / 1000000;
	target.tv_usec %= 1000000;
	usleep(time_ms * 700);
	// usleep(500);
	gettimeofday(&now, NULL);
	while (now.tv_sec < target.tv_sec || now.tv_usec < target.tv_usec)
	{
		usleep(1000);
		gettimeofday(&now, NULL);
	}
	return ;
}

static void	*routine(void *arg)
{
	t_info	*info;

	info = (t_info *)arg;
	if (info->id % 2 != 0)
		usleep(1000);
	while (info->args->died != 1)
	{
		if (take_both_fork(info) == 0)
			break ;
		print_msg(info, EAT);
		sleep_func(info, info->args->eat_ms);
		put_back_both_forks(info);
		print_msg(info, SLEEP);
		sleep_func(info, info->args->sleep_ms);
		print_msg(info, THINK);
	}
	return (NULL);
}

int	create_threads(pthread_t **philo, t_info *info)
{
	int		i;
	int		error;
	int		phil_num;

	phil_num = info->args->phil_num;
	*philo = (pthread_t *)malloc(sizeof(pthread_t) * phil_num);
	if (*philo == NULL)
	{
		free(info->args->fork);
		return (0);
	}
	i = 0;
	while (i < phil_num)
	{
		error = pthread_create(&(*philo)[i], NULL, routine, (void *)&(info[i]));
		if (error != 0)
		{
			free(info->args->fork);
			free(philo);
			return (0);
		}
		++i;
	}
	return (1);
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
