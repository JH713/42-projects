/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 22:00:08 by jihyeole          #+#    #+#             */
/*   Updated: 2023/05/10 02:01:39 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_err_msg(char *command, char *err_msg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(command, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(err_msg, 2);
}

void	print_perror(char *msg)
{
	ft_putstr_fd("minishell: ", 2);
	perror(msg);
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
		{
			print_perror(command);
			return (NULL);
		}
		full_path = ft_strdup(command);
	}
	else
	{
		i = 0;
		while (path[i])
		{
			full_path = ft_strjoin(path[i], command);
			if (access(full_path, X_OK) == 0)
				return (full_path);
			free(full_path);
			++i;
		}
		print_err_msg(command, "command not found");
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
		full_path = execute_check(command, path);
		if (full_path == NULL)
			continue ;
		ft_printf("%s\n", full_path);
		free(full_path);
		free(command);
	}
}
