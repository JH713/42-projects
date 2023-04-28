/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 23:20:06 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/28 23:24:25 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	open_sems(t_info *info)
{
	t_args	*args;

	args = info->args;
	sem_unlink("/fork");
	sem_unlink("/msg");
	sem_unlink("/die");
	info->sem_fork = sem_open("/fork", O_CREAT | O_EXCL, 0600, args->phil_num);
	if (info->sem_fork == SEM_FAILED)
		print_perror("sem_open");
	info->sem_msg = sem_open("/msg", O_CREAT | O_EXCL, 0600, 1);
	if (info->sem_msg == SEM_FAILED)
		print_perror("sem_open");
	info->sem_die = sem_open("/die", O_CREAT | O_EXCL, 0600, 0);
	if (info->sem_die == SEM_FAILED)
		print_perror("sem_open");
}

void	close_and_unlink_sems(t_info *info)
{
	if (sem_close(info->sem_fork) == -1)
		print_perror("sem_close");
	if (sem_close(info->sem_msg) == -1)
		print_perror("sem_close");
	if (sem_close(info->sem_die) == -1)
		print_perror("sem_close");
	if (sem_unlink("/fork") == -1)
		print_perror("sem_unlink");
	if (sem_unlink("/msg") == -1)
		print_perror("sem_unlink");
	if (sem_unlink("/die") == -1)
		print_perror("sem_unlink");
}