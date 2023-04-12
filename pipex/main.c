/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 02:55:14 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/12 12:43:38 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		fds[2];
	pid_t	pid;
	int		status;

	if (argc != 5)
		print_error("need 4 arguments", 1);
	if (pipe(fds) == -1)
		print_error("pipe", 0);
	pid = fork();
	if (pid == -1)
		print_error("fork", 0);
	if (pid == 0)
	{
		child_process(fds, argv[1], argv[2], env);
	}
	else
	{
		waitpid(pid, &status, 0);
		parent_process(fds, argv[4], argv[3], env);
	}
}
