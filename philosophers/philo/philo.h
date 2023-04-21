/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:57:27 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/21 23:32:15 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <string.h>

enum e_state {
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIED
};

typedef struct s_args{
	int				phil_num;
	int				die_ms;
	int				eat_ms;
	int				sleep_ms;
	int				meal_cnt;
	int				*fork_available;	
	pthread_mutex_t	*fork;
	pthread_mutex_t	*msg;
	struct timeval	start;
	struct timeval	last_meal;
	int				died;
}	t_args;

typedef struct s_info{
	int				id;
	t_args			*args;
}	t_info;

#endif