/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:16:09 by jihyeole          #+#    #+#             */
/*   Updated: 2023/05/01 19:33:08 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_finished(t_info *info)
{
	int	finished;

	pthread_mutex_lock(&(info->args->flag));
	finished = info->args->finished;
	pthread_mutex_unlock(&(info->args->flag));
	return (finished);
}

void	set_died_flag(t_info *info)
{
	pthread_mutex_lock(&(info->args->flag));
	info->args->died = 1;
	pthread_mutex_unlock(&(info->args->flag));
}

int	get_time_spent(struct timeval *now, t_info *info, int i)
{
	int	time_spent;

	pthread_mutex_lock(&(info->args->meal));
	time_spent = (now->tv_sec - info[i].last_meal.tv_sec) * 1000 \
	+ (now->tv_usec - info[i].last_meal.tv_usec) / 1000;
	pthread_mutex_unlock(&(info->args->meal));
	return (time_spent);
}

void	monitoring(t_info *info)
{
	int				i;
	struct timeval	now;

	while (1)
	{
		usleep(1000);
		if (get_finished(info) == info->args->phil_num)
			set_died_flag(info);
		i = 0;
		gettimeofday(&now, NULL);
		while (i < info->args->phil_num)
		{
			if (get_time_spent(&now, info, i) >= info->args->die_ms)
			{
				set_died_flag(info);
				print_msg(&info[i], DIED);
				break ;
			}
			++i;
		}
		if (get_died(info->args) == 1)
			break ;
	}
}
