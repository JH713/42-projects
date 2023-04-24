/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:15:21 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/24 20:15:39 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_info	*get_info(t_args *args, pthread_mutex_t *fork, pthread_mutex_t *msg)
{
	struct timeval	start;
	t_info			*info;
	int				i;

	gettimeofday(&start, NULL);
	args->fork = fork;
	args->msg = msg;
	args->start = start;
	args->died = 0;
	args->finished = 0;
	info = (t_info *)malloc(sizeof(t_info) * args->phil_num);
	if (info == NULL)
		print_perror("malloc");
	i = 0;
	while (i < args->phil_num)
	{
		info[i].last_meal = start;
		info[i].meal_cnt = args->meal_cnt;
		info[i].id = i + 1;
		info[i].args = args;
		++i;
	}
	return (info);
}

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
