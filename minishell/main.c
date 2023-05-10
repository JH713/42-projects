/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 22:00:08 by jihyeole          #+#    #+#             */
/*   Updated: 2023/05/11 00:04:12 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_path(char **env)
{
	char	**path;
	int		i;
	char	*temp;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		++i;
	if (env[i])
		path = ft_split(&env[i][5], ':');
	else
		path = NULL;
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

char	*execute_check(char *command, char **path)
{
	int		i;
	char	*full_path;

	if (command[0] == '.' || command[0] == '/')
	{
		if (access(command, X_OK) != 0)
		{
			minishell_perror(command);
			return (NULL);
		}
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
	minishell_err_msg(command, "command not found");
	return (NULL);
}

void	print_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		ft_putendl_fd(env[i], 1);
		++i;
	}
}

int	main(int argc, char **argv, char **env)
{
	char	*command;
	char	**path;
	char	*full_path;

	(void)argv;
	if (argc != 1)
		print_error_with_exit("Error: Invalid number of arguments.");
	path = get_path(env);
	while (1)
	{
		command = readline("minishell$ ");
		if (ft_strlen(command) != 0)
			add_history(command);
		if (ft_strncmp(command, "exit", 5) == 0)
		{
			ft_printf("exit\n");
			free(command);
			break ;
		}
		else if (ft_strncmp(command, "env", 4) == 0)
		{
			print_env(env);
			free(command);
			break ;
		}
		full_path = execute_check(command, path);
		if (full_path == NULL)
			continue ;
		ft_printf("%s\n", full_path);
		free(full_path);
		free(command);
	}
}
