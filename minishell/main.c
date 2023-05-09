/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 22:00:08 by jihyeole          #+#    #+#             */
/*   Updated: 2023/05/09 16:27:39 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
			print_perror("access");
		full_path = ft_strdup(command);
	}
	else
	{
		i = 0;
		while (path[i])
		{
			full_path = ft_strjoin(path[i], command);
			if (access(command, F_OK) == 0)
				return (full_path);
			free(full_path);
			++i;
		}
		ft_printf("command not found\n");
		return (NULL);
	}
	return (full_path);
}

int	main(int argc, char **argv, char **env)
{
	char	*command;
	char	**path;
	char	*full_path;

	(void)argv;
	if (argc != 1)
		print_error("Error: Invalid number of arguments.\nUsage: ./minishell");
	path = get_path(env);
	int i = 0;
	while(path[i])
	{
		ft_printf("%s\n", path[i]);
		i++;
	}
	while (1)
	{
		command = readline("minishell$ ");
		if (ft_strlen(command) != 0)
			add_history(command);
		if (ft_strncmp(command, "exit", 5) == 0)
		{
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
