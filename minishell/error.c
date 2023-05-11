/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 23:30:46 by jihyeole          #+#    #+#             */
/*   Updated: 2023/05/10 23:32:07 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell_err_msg(char *command, char *err_msg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(command, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(err_msg, 2);
}

void	minishell_perror(char *msg)
{
	ft_putstr_fd("minishell: ", 2);
	perror(msg);
}

void	print_error_with_exit(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(1);
}