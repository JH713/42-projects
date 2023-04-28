/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:52:31 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/29 00:00:25 by jihyeole         ###   ########.fr       */
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
void	open_sems(t_info *info);
void	close_and_unlink_sems(t_info *info);
void	philosopher_process(t_info *info);
void	wait_all_child(pid_t *pid, int phil_num);
int		get_passed_time_ms(t_info *info, enum e_state state);
void	kill_processes(t_info *info);
void	philo_process(t_info *info);
t_args	check_and_store_args(int ac, char *av[]);
void	init_info(t_info *info, t_args *args);

#endif