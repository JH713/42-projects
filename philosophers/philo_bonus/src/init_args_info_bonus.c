/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args_info_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 23:59:37 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/29 00:00:38 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
		args.meal_cnt = -1;
	return (args);
}

void	init_info(t_info *info, t_args *args)
{
	info->args = args;
	info->pid = (pid_t *)malloc(sizeof(pid_t) * args->phil_num);
	if (info->pid == NULL)
		print_perror("pid malloc");
	gettimeofday(&(info->start), NULL);
	info->last_meal = info->start;
}
