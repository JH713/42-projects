/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:05:45 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/24 20:06:08 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_mutexs(pthread_mutex_t **fork, int num, pthread_mutex_t *msg)
{
	int	i;

	*fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num);
	if (*fork == NULL)
		print_perror("malloc");
	i = 0;
	while (i < num)
	{
		if (pthread_mutex_init(&(*fork)[i], NULL) != 0)
			print_perror("pthread_mutex_init");
		++i;
	}
	if (pthread_mutex_init(msg, NULL) != 0)
		print_perror("pthread_mutex_init");
}

void	destroy_mutexs(pthread_mutex_t **fork, int num, pthread_mutex_t *msg)
{
	int	i;

	i = 0;
	while (i < num)
	{
		if (pthread_mutex_destroy(&(*fork)[i]) != 0)
			print_perror("fork pthread_mutex_destroy");
		++i;
	}
	free(*fork);
	*fork = NULL;
	if (pthread_mutex_destroy(msg) != 0)
		print_perror("msg pthread_mutex_destroy");
}
