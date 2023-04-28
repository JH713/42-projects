/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:45:30 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/28 23:52:55 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_isblank(char c)
{
	if (c == ' ' || c == '\t' || c == '\v')
		return (1);
	else if (c == '\f' || c == '\n' || c == '\r')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	long long	result;
	int			is_positive;

	result = 0;
	is_positive = 1;
	while (ft_isblank(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		is_positive = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * is_positive);
}

void	wait_all_child(pid_t *pid, int phil_num)
{
	int	i;
	int	status;

	i = 0;
	while (i < phil_num)
	{
		waitpid(pid[i], &status, 0);
		++i;
	}
}

int	get_passed_time_ms(t_info *info, enum e_state state)
{
	struct timeval	start;
	struct timeval	now;
	long long		passed_time;

	start = info->start;
	gettimeofday(&now, NULL);
	if (state == EAT)
		info->last_meal = now;
	passed_time = (now.tv_sec - start.tv_sec) * 1000 \
	+ (now.tv_usec - start.tv_usec) / 1000;
	return ((int) passed_time);
}

void	kill_processes(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->args->phil_num)
	{
		sem_wait(info->sem_die);
		++i;
	}
	i = 0;
	while (i < info->args->phil_num)
	{
		kill(info->pid[i], SIGKILL);
		++i;
	}
}
