/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 07:55:13 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/14 07:56:21 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

char	**get_exec_argv(int n, t_arg_info *arg_info)
{
	char	**exec_argv;
	char	*full_path;
	char	**path;

	exec_argv = ft_split(arg_info->argv[n + 2], ' ');
	path = get_path(arg_info->env);
	full_path = check_path(path, exec_argv[0]);
	if (full_path == NULL)
		print_error("no such command in path", 1);
	free(exec_argv[0]);
	exec_argv[0] = full_path;
	return (exec_argv);
}
