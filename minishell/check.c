/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:06:29 by jihyeole          #+#    #+#             */
/*   Updated: 2023/05/17 23:07:53 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fd_check(char *fd)
{
	int	fd_num;

	if (ft_strlen(fd) > 3)
		minishell_error(fd, strerror(9));
	fd_num = ft_atoi(fd);
	if (fd_num >= 256)
		minishell_error(fd, strerror(9));
	return (fd_num);
}

char	*execute_check(char *command, char **path)
{
	int		i;
	char	*full_path;

	if (command[0] == '.' || command[0] == '/')
	{
		if (access(command, X_OK) != 0)
			minishell_perror(command);
		return (ft_strdup(command));
	}
	i = 0;
	while (path[i])
	{
		full_path = ft_strjoin(path[i], command);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		++i;
	}
	minishell_error(command, "command not found");
	return (NULL);
}
