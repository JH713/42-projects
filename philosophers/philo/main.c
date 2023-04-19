/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:01:03 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/20 00:13:40 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (*(s + cnt))
		cnt++;
	return (cnt);
}	

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	check_num(char *num)
{
	while (*num)
	{
		if (!ft_isdigit(*num))
			return (0);
		num++;
	}
	return (1);
}

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}

void	print_perror(char *msg)
{
	perror(msg);
	exit(1);
}

void	print_error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(1);
}

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

int	is_positive_int(char *num)
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

t_args	check_and_store_args(int ac, char *av[])
{
	t_args	args;

	if (ac != 5 && ac != 6)
		print_error("Please input 4 to 5 arguments.");
	args.phil_num = check_and_get_int(av[1]);
	args.die_ms = check_and_get_int(av[2]);
	args.eat_ms = check_and_get_int(av[3]);
	args.sleep_ms = check_and_get_int(av[4]);
	if (ac == 6)
		args.meal_cnt = check_and_get_int(av[5]);
	else
		args.meal_cnt = 0;
	return (args);
}

void	*routine(void *arg)
{
	if (arg)
		return (NULL);
	printf("1\n");
	return (NULL);
}

void	create_threads(pthread_t **philo, int phil_num)
{
	int i;

	*philo = (pthread_t *)malloc(sizeof(pthread_t) * phil_num);
	if (*philo == NULL)
		print_perror("malloc");
	i = 0;
	while (i < phil_num)
	{
		if (pthread_create(&(*philo)[i], NULL, routine, NULL) != 0)
			print_perror("pthread_create");
		++i;
	}
}

void	create_mutexs(pthread_mutex_t **fork, int phil_num)
{
	int	i;

	*fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * phil_num);
	if (*fork == NULL)
		print_perror("malloc");
	i = 0;
	while (i < phil_num)
	{
		if (pthread_mutex_init(&(*fork)[i], NULL) != 0)
			print_perror("pthread_mutex_init");
		++i;
	}
}

void	destroy_mutexs(pthread_mutex_t **fork, int phil_num)
{
	int	i;

	i = 0;
	while (i < phil_num)
	{
		if (pthread_mutex_destroy(&(*fork)[i]) != 0)
			print_perror("pthread_mutex_destroy");
		++i;
	}
	free(*fork);
	*fork = NULL;
}

int	main(int ac, char **av)
{
	t_args			args;
	pthread_t		*philo;
	pthread_mutex_t *fork;

	args = check_and_store_args(ac, av);
	create_threads(&philo, args.phil_num);
	create_mutexs(&fork, args.phil_num);
	
	int i = 0;
	while (i < args.phil_num)
	{
		pthread_join(philo[i], NULL);
		++i;
	}
	destroy_mutexs(&fork, args.phil_num);
}
