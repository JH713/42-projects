/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:15:21 by jihyeole          #+#    #+#             */
/*   Updated: 2023/05/01 03:52:16 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_and_store_args(t_args *args, int ac, char *av[])
{
	if (ac != 5 && ac != 6)
	{
		print_error("Please input 4 to 5 arguments.");
		return (0);
	}
	args->phil_num = check_and_get_int(av[1]);
	args->die_ms = check_and_get_int(av[2]);
	args->eat_ms = check_and_get_int(av[3]);
	args->sleep_ms = check_and_get_int(av[4]);
	if (ac == 6)
		args->meal_cnt = check_and_get_int(av[5]);
	else
		args->meal_cnt = -2;
	if (args->phil_num == -1 || args->die_ms == -1 || \
	args->eat_ms == -1 || args->sleep_ms == -1 || args->meal_cnt == -1)
	{
		print_error("The arguments must be positive integers.");
		return (0);
	}
	return (1);
}

static void	init_args(t_args *args, pthread_mutex_t *fork, pthread_mutex_t *msg)
{
	args->fork = fork;
	args->msg = msg;
	args->died = 0;
	args->finished = 0;
}

t_info	*get_info(t_args *args, pthread_mutex_t *fork, pthread_mutex_t *msg)
{
	t_info			*info;
	int				i;
	struct timeval	start;

	init_args(args, fork, msg);
	info = (t_info *)malloc(sizeof(t_info) * args->phil_num);
	if (info == NULL)
	{
		free(args->fork);
		return (NULL);
	}
	i = 0;
	gettimeofday(&start, NULL);
	args->start = start;
	while (i < args->phil_num)
	{
		info[i].last_meal = start;
		info[i].meal_cnt = args->meal_cnt;
		info[i].id = i + 1;
		info[i].args = args;
		info[i].left_fork = &(args->fork)[info[i].id - 1];
		info[i].right_fork = &(args->fork)[info[i].id % args->phil_num];
		++i;
	}
	return (info);
}
