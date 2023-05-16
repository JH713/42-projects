/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 23:30:46 by jihyeole          #+#    #+#             */
/*   Updated: 2023/05/16 17:18:44 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell_error(char *command, char *err_msg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(command, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(err_msg, 2);
	exit(1);
}

void	minishell_perror(char *msg)
{
	ft_putstr_fd("minishell: ", 2);
	perror(msg);
	exit(1);
}

void	print_error(char *msg, int status)
{
	if (status == 0)
		perror(msg);
	else if (status == 1)
		ft_putendl_fd(msg, 2);
	exit(1);
}
