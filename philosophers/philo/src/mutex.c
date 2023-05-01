/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:05:45 by jihyeole          #+#    #+#             */
/*   Updated: 2023/05/01 18:15:28 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_mutexes(t_args *args, int num)
{
	int	i;

	if (pthread_mutex_init(&(args->msg), NULL) != 0)
		return (0);
	if (pthread_mutex_init(&(args->flag), NULL) != 0)
		return (0);
	if (pthread_mutex_init(&(args->meal), NULL) != 0)
		return (0);
	args->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num);
	if (args->fork == NULL)
		return (0);
	i = 0;
	while (i < num)
	{
		if (pthread_mutex_init(&(args->fork)[i], NULL) != 0)
		{
			free(args->fork);
			return (0);
		}
		++i;
	}
	return (1);
}

int	destroy_mutexes(t_args *args, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		if (pthread_mutex_destroy(&(args->fork)[i]) != 0)
			return (0);
		++i;
	}
	free(args->fork);
	args->fork = NULL;
	if (pthread_mutex_destroy(&(args->msg)) != 0)
		return (0);
	if (pthread_mutex_destroy(&(args->flag)) != 0)
		return (0);
	if (pthread_mutex_destroy(&(args->meal)) != 0)
		return (0);
	return (1);
}
