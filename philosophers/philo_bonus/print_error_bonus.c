/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:46:21 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/29 16:12:50 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	ft_putendl_fd(char *s, int fd)
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
