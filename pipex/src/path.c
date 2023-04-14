/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:47:20 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/14 08:20:50 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	**get_path(char **env)
{
	int		i;
	char	**path;
	char	*temp;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = ft_split(&env[i][5], ':');
			i = 0;
			while (path[i])
			{
				temp = path[i];
				path[i] = ft_strjoin(path[i], "/");
				free(temp);
				++i;
			}
			return (path);
		}
		++i;
	}
	print_error("no path in env", 1);
	return (NULL);
}

char	*check_path(char **env, char *cmd)
{
	int		i;
	char	*full_path;

	i = 0;
	while (env[i])
	{
		full_path = ft_strjoin(env[i], cmd);
		if (access(full_path, F_OK) == 0)
			return (full_path);
		free(full_path);
		++i;
	}
	return (NULL);
}
