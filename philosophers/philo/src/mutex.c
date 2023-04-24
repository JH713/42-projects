/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:05:45 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/24 21:25:07 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_mutexes(pthread_mutex_t **fork, int num, pthread_mutex_t *msg)
{
	int	i;

	if (pthread_mutex_init(msg, NULL) != 0)
		return (0);
	*fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num);
	if (*fork == NULL)
		return (0);
	i = 0;
	while (i < num)
	{
		if (pthread_mutex_init(&(*fork)[i], NULL) != 0)
		{
			free(fork);
			return (0);
		}
		++i;
	}
	return (1);
}

int	destroy_mutexes(pthread_mutex_t **fork, int num, pthread_mutex_t *msg)
{
	int	i;

	i = 0;
	while (i < num)
	{
		if (pthread_mutex_destroy(&(*fork)[i]) != 0)
			return (0);
		++i;
	}
	free(*fork);
	*fork = NULL;
	if (pthread_mutex_destroy(msg) != 0)
		return (0);
	return (1);
}
