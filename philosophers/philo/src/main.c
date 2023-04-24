/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:01:03 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/24 20:21:58 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_args			args;
	pthread_t		*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	msg;
	t_info			*info;

	args = check_and_store_args(ac, av);
	create_mutexs(&fork, args.phil_num, &msg);
	info = get_info(&args, fork, &msg);
	create_threads(&philo, info);
	monitoring(info);
	join_threads(philo, &args);
	destroy_mutexs(&fork, args.phil_num, &msg);
	free(philo);
	free(fork);
}
