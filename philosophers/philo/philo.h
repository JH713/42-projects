/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:57:27 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/20 16:52:03 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_args{
	int	phil_num;
	int	die_ms;
	int	eat_ms;
	int	sleep_ms;
	int	meal_cnt;
}	t_args;

typedef struct s_info{
	int				id;
	t_args			*args;
	pthread_mutex_t	*fork;
	struct timeval	*start;
}	t_info;

#endif