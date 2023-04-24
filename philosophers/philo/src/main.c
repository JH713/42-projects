/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:01:03 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/24 22:49:47 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_func(pthread_mutex_t *fork, t_info *info, pthread_t *philo)
{
	free(fork);
	free(info);
	free(philo);
}

int	main(int ac, char **av)
{
	t_args			args;
	pthread_t		*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	msg;
	t_info			*info;

	if (check_and_store_args(&args, ac, av) == 0)
		return (1);
	if (create_mutexes(&fork, args.phil_num, &msg) == 0)
		return (print_error("create_mutexes error"));
	info = get_info(&args, fork, &msg);
	if (info == NULL)
		return (print_error("info malloc error"));
	if (create_threads(&philo, info) == 0)
		return (print_error("info malloc error"));
	monitoring(info);
	join_threads(philo, &args);
	if (destroy_mutexes(&fork, args.phil_num, &msg) == 0)
	{
		free_func(fork, info, philo);
		return (print_error("destroy_mutexes error"));
	}
	free_func(fork, info, philo);
	return (0);
}
