/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:06:41 by jihyeole          #+#    #+#             */
/*   Updated: 2023/05/01 19:39:17 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	sleep_func(int time_ms)
{
	struct timeval	start;
	struct timeval	now;
	long long		target;

	gettimeofday(&start, NULL);
	target = start.tv_sec * 1000 + start.tv_usec / 1000 + time_ms;
	usleep(time_ms * 700);
	gettimeofday(&now, NULL);
	while (now.tv_sec * 1000 + now.tv_usec / 1000 <= target)
	{
		usleep(100);
		gettimeofday(&now, NULL);
	}
}

int	get_died(t_args *args)
{
	int	died;

	pthread_mutex_lock(&(args->flag));
	died = args->died;
	pthread_mutex_unlock(&(args->flag));
	return (died);
}

static void	*routine(void *arg)
{
	t_info	*info;

	info = (t_info *)arg;
	if (info->id % 2 != 0)
		usleep(2000);
	while (get_died(info->args) != 1)
	{
		if (take_both_fork(info) == 0)
			break ;
		print_msg(info, EAT);
		if (get_died(info->args) == 1)
		{
			put_back_both_forks(info);
			break ;
		}
		sleep_func(info->args->eat_ms);
		put_back_both_forks(info);
		print_msg(info, SLEEP);
		if (get_died(info->args) == 1)
			break ;
		sleep_func(info->args->sleep_ms);
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
