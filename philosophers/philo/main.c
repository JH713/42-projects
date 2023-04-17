/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:01:03 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/17 23:45:40 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	*routine(void)
{
	return (NULL);
}

int	main(int ac, char **av)
{
	pthread_t	*t;
	int			phil_num;
	int			i;

	if (ac != 5 || ac != 6)
		return (1);
	phil_num = ft_atoi(av[1]);
	t = (pthread_t *)malloc(sizeof(pthread_t) * phil_num);
	i = 0;
	while (i < phil_num)
	{
		pthread_create(&t[i], NULL, &routine, NULL);
		++i;
	}
}
