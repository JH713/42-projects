/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:01:03 by jihyeole          #+#    #+#             */
/*   Updated: 2023/05/01 19:48:52 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_args		args;
	pthread_t	*philo;
	t_info		*info;

	if (check_and_store_args(&args, ac, av) == 0)
		return (1);
	if (create_mutexes(&args, args.phil_num) == 0)
		return (print_error("create_mutexes error"));
	info = get_info(&args);
	if (info == NULL)
		return (print_error("info malloc error"));
	if (create_threads(&philo, info) == 0)
		return (print_error("info malloc error"));
	monitoring(info);
	join_threads(philo, &args);
	if (destroy_mutexes(&args, args.phil_num) == 0)
	{
		free_func(args.fork, info, philo);
		return (print_error("destroy_mutexes error"));
	}
	free_func(args.fork, info, philo);
	return (0);
}
