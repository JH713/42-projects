/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:12:44 by jihyeole          #+#    #+#             */
/*   Updated: 2023/05/01 05:10:01 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	get_passed_time_ms(t_info *info, enum e_state state)
{
	struct timeval	start;
	struct timeval	now;
	long long		passed_time;

	start = info->args->start;
	gettimeofday(&now, NULL);
	if (state == EAT)
		info->last_meal = now;
	passed_time = (now.tv_sec - start.tv_sec) * 1000 \
	+ (now.tv_usec - start.tv_usec) / 1000;
	return ((int) passed_time);
}

void	meal_count(t_info *info)
{
	if (info->meal_cnt > 0)
		info->meal_cnt--;
	if (info->meal_cnt == 0)
		info->args->finished++;
}

void	print_msg(t_info *info, enum e_state state)
{
	int	passed_time;

	if (info->args->died == 1 && state != DIED)
		return ;
	pthread_mutex_lock(info->args->msg);
	passed_time = get_passed_time_ms(info, state);
	if (info->args->died == 1)
	{
		if (state == DIED)
			printf("%d %d died\n", passed_time, info->id);
	}
	else if (state == FORK)
		printf("%d %d has taken a fork\n", passed_time, info->id);
	else if (state == EAT)
	{
		printf("%d %d is eating\n", passed_time, info->id);
		meal_count(info);
	}
	else if (state == SLEEP)
		printf("%d %d is sleeping\n", passed_time, info->id);
	else if (state == THINK)
		printf("%d %d is thinking\n", passed_time, info->id);
	pthread_mutex_unlock(info->args->msg);
}
