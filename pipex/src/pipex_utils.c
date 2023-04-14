/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:43:43 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/14 08:20:55 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	print_error(char *msg, int status)
{
	if (status == 0)
		perror(msg);
	else if (status == 1)
		ft_putendl_fd(msg, 2);
	exit(1);
}

static void	redirect_input_output(int input, int output)
{
	close(0);
	dup2(input, 0);
	close(input);
	close(1);
	dup2(output, 1);
	close(output);
}

void	child_process(int fds[2], char *file, char *cmd, char **env)
{
	int		fd;
	char	**exec_argv;
	char	*full_path;
	char	**path;

	close(fds[0]);
	if (file[0] != '/')
		file = ft_strjoin("./", file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error("open file1", 0);
	if (file[0] != '/')
		free(file);
	redirect_input_output(fd, fds[1]);
	exec_argv = ft_split(cmd, ' ');
	path = get_path(env);
	full_path = check_path(path, exec_argv[0]);
	if (full_path == NULL)
		print_error("no such command in path", 1);
	free(exec_argv[0]);
	exec_argv[0] = full_path;
	execve(exec_argv[0], exec_argv, env);
	perror(exec_argv[0]);
	exit(1);
}

void	parent_process(int fds[2], char *file, char *cmd, char **env)
{
	int		fd;
	char	**exec_argv;
	char	*full_path;
	char	**path;

	close(fds[1]);
	if (file[0] != '/')
		file = ft_strjoin("./", file);
	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		print_error("open file2", 0);
	if (file[0] != '/')
		free(file);
	redirect_input_output(fds[0], fd);
	exec_argv = ft_split(cmd, ' ');
	path = get_path(env);
	full_path = check_path(path, exec_argv[0]);
	if (full_path == NULL)
		print_error("no such command in path", 1);
	free(exec_argv[0]);
	exec_argv[0] = full_path;
	execve(exec_argv[0], exec_argv, env);
	perror(exec_argv[0]);
	exit(1);
}
