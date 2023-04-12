/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 22:12:14 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/12 12:45:13 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "./libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

void	print_error(char *msg, int status);
void	child_process(int fds[2], char *file, char *cmd, char **env);
void	parent_process(int fds[2], char *file, char *cmd, char **env);
char	**get_path(char **env);
char	*check_path(char **env, char *cmd);

#endif