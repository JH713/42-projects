/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:42:33 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/24 19:48:03 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (*(s + cnt))
		cnt++;
	return (cnt);
}	

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static int	check_num(char *num)
{
	while (*num)
	{
		if (!ft_isdigit(*num))
			return (0);
		num++;
	}
	return (1);
}

static int	is_positive_int(char *num)
{
	if (ft_strlen(num) > 10 || !check_num(num))
		return (0);
	if (ft_strlen(num) == 10)
	{
		if (*num != '1' && *num != '2')
			return (0);
		if (ft_atoi(num) < 0)
			return (0);
	}
	if (ft_atoi(num) == 0)
		return (0);
	return (1);
}

int	check_and_get_int(char *str)
{
	if (!is_positive_int(str))
		print_error("The arguments must be positive integers.");
	return (ft_atoi(str));
}
