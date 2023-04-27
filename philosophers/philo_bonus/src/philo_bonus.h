/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:52:31 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/27 16:47:05 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <semaphore.h>
# include <signal.h>

typedef enum e_state {
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIED
}	t_state;

typedef struct s_args{
	int				phil_num;
	int				die_ms;
	int				eat_ms;
	int				sleep_ms;
	int				meal_cnt;
}	t_args;

typedef struct s_info{
	int				id;
	t_args			*args;
	sem_t			*sem_fork;
	sem_t			*sem_msg;
	sem_t			*sem_die;
	pid_t			*pid;
	struct timeval	start;
	struct timeval	last_meal;
}	t_info;

int		ft_atoi(const char *str);
int		check_and_get_int(char *str);
void	print_perror(char *msg);
void	print_error(char *msg);

#endif