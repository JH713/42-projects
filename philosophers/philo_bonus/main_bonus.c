/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:52:34 by jihyeole          #+#    #+#             */
/*   Updated: 2023/05/02 17:43:59 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_args			args;
	t_info			info;

	args = check_and_store_args(ac, av);
	init_info(&info, &args);
	open_sems(&info);
	gettimeofday(&(info.start), NULL);
	info.last_meal = info.start;
	philo_process(&info);
	kill_processes(&info);
	wait_all_child(info.pid, args.phil_num);
	close_and_unlink_sems(&info);
	free(info.pid);
}
