/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:03:43 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/30 22:42:36 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_fork(pthread_mutex_t *fork, t_info *info)
{
	pthread_mutex_lock(fork);
	print_msg(info, FORK);
}

int	take_both_fork(t_info *info)
{
	int				right_fork;
	int				left_fork;
	// int				_kill;

	// pthread_mutex_lock(info->args->msg);
	// _kill = info->args->died;
	// pthread_mutex_unlock(info->args->msg);
	// if (_kill)
	// 	return 0;

	if (info->args->died == 1)
		return (0);
	right_fork = info->id % info->args->phil_num;
	left_fork = info->id - 1;
	if (info->args->phil_num == 1)
	{
		take_fork(&(info->args->fork)[right_fork], info);
		while (info->args->died != 1)
			;
		pthread_mutex_unlock(&(info->args->fork[0]));
		return (0);
	}
	if (info->id % 2 != 0)
	{
		take_fork(&(info->args->fork)[right_fork], info);
		take_fork(&(info->args->fork)[left_fork], info);
	}
	else
	{
		take_fork(&(info->args->fork)[left_fork], info);
		take_fork(&(info->args->fork)[right_fork], info);
	}
	if (info->args->died == 1)
	{
		put_back_both_forks(info);
		return (0);
	}
	return (1);
}

void	put_back_both_forks(t_info *info)
{
	int				right_fork;
	int				left_fork;

	right_fork = info->id % info->args->phil_num;
	left_fork = info->id - 1;
	pthread_mutex_unlock(&(info->args->fork[right_fork]));
	pthread_mutex_unlock(&(info->args->fork[left_fork]));
}
