/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:57:27 by jihyeole          #+#    #+#             */
/*   Updated: 2023/05/01 19:38:09 by jihyeole         ###   ########.fr       */
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
	pthread_mutex_t	msg;
	pthread_mutex_t	flag;
	pthread_mutex_t	meal;
	struct timeval	start;
	int				died;
	int				finished;
}	t_args;

typedef struct s_info{
	int				id;
	int				meal_cnt;
	struct timeval	last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_args			*args;
}	t_info;

int		check_and_get_int(char *str);
int		ft_atoi(const char *str);
int		print_error(char *msg);
int		take_both_fork(t_info *info);
void	put_back_both_forks(t_info *info);
int		create_mutexes(t_args *args, int num);
int		destroy_mutexes(t_args *args, int num);
int		create_threads(pthread_t **philo, t_info *info);
void	join_threads(pthread_t *philo, t_args *args);
void	print_msg(t_info *info, enum e_state state);
t_info	*get_info(t_args *args);
int		check_and_store_args(t_args *args, int ac, char *av[]);
void	monitoring(t_info *info);
void	free_func(pthread_mutex_t *fork, t_info *info, pthread_t *philo);
int		get_died(t_args *args);

#endif