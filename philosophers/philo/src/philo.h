/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:57:27 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/24 20:37:52 by jihyeole         ###   ########.fr       */
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
	pthread_mutex_t	*fork;
	pthread_mutex_t	*msg;
	struct timeval	start;
	int				died;
	int				finished;
}	t_args;

typedef struct s_info{
	int				id;
	int				meal_cnt;
	struct timeval	last_meal;
	t_args			*args;
}	t_info;

int		check_and_get_int(char *str);
int		ft_atoi(const char *str);
void	print_perror(char *msg);
void	print_error(char *msg);
int		take_both_fork(t_info *info);
void	put_back_both_forks(t_info *info);
void	create_mutexs(pthread_mutex_t **fork, int num, pthread_mutex_t *msg);
void	destroy_mutexs(pthread_mutex_t **fork, int num, pthread_mutex_t *msg);
void	create_threads(pthread_t **philo, t_info *info);
void	join_threads(pthread_t *philo, t_args *args);
void	print_msg(t_info *info, enum e_state state);
t_info	*get_info(t_args *args, pthread_mutex_t *fork, pthread_mutex_t *msg);
t_args	check_and_store_args(int ac, char *av[]);
void	monitoring(t_info *info);

#endif