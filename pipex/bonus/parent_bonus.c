/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 07:58:53 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/14 08:41:12 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	parent(int fds[2], char *file, char *cmd, char **env)
{
	int		fd;
	char	**exec_argv;
	char	*full_path;
	char	**path;

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

void	hd_parent(int fds[2], char *file, char *cmd, char **env)
{
	int		fd;
	char	**exec_argv;
	char	*full_path;
	char	**path;

	close(fds[1]);
	if (file[0] != '/')
		file = ft_strjoin("./", file);
	fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
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

void	parent_process(t_process *process, int argc, char **argv, char **env)
{
	if (argc - 6 >= 0)
		close(process[argc - 6].fd[0]);
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		hd_parent(process[argc - 5].fd, argv[argc - 1], argv[argc - 2], env);
	else
	{
		if (argc != 5)
			close(process[argc - 5].fd[1]);
		parent(process[argc - 5].fd, argv[argc - 1], argv[argc - 2], env);
	}
}
