/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:16:09 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/29 20:00:00 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitoring(t_info *info)
{
	t_args			*args;
	int				i;
	struct timeval	now;
	int				time_spent;

	args = info->args;
	while (args->died != 1)
	{
		usleep(100);
		if (args->finished == args->phil_num)
			args->died = 1;
		i = 0;
		gettimeofday(&now, NULL);
		while (args->died != 1 && i < args->phil_num)
		{
			time_spent = (now.tv_sec - info[i].last_meal.tv_sec) * 1000 \
			+ (now.tv_usec - info[i].last_meal.tv_usec) / 1000;
			if (time_spent >= args->die_ms)
			{
				args->died = 1;
				print_msg(&info[i], DIED);
			}
			++i;
		}
	}
}
