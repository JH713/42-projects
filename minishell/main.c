/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 22:00:08 by jihyeole          #+#    #+#             */
/*   Updated: 2023/05/08 16:05:09 by jihyeole         ###   ########.fr       */
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

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		++i;
	if (env[i])
		path = ft_split(&env[i][5], ':');
	else
		path = NULL;
	return (path);
}

int	main(int argc, char **argv, char **env)
{
	char	*command;
	char	**path;

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
			free(command);
			break ;
		}
		free(command);
	}
}
