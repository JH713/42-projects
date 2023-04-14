/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 07:59:37 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/14 08:02:16 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	heredoc_first_process(t_process *process, int process_cnt, char *end)
{
	char	*line;

	end = ft_strjoin(end, "\n");
	process[0].pid = fork();
	if (process[0].pid == -1)
		print_error("fork", 0);
	if (process[0].pid == 0)
	{
		close_all_fds(1, process_cnt - 1, process);
		close(process[0].fd[0]);
		close(1);
		dup2(process[0].fd[1], 1);
		close(process[0].fd[1]);
		line = get_next_line(0);
		while (ft_strncmp(end, line, ft_strlen(end) + 1) != 0)
		{
			write(1, line, ft_strlen(line));
			line = get_next_line(0);
		}
		exit(1);
	}
	close(process[0].fd[1]);
}

static void	child_process(int fds[2], char *file, char *cmd, char **env)
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

void	first_process(t_process *proc, int proc_cnt, char **argv, char **env)
{
	proc[0].pid = fork();
	if (proc[0].pid == -1)
		print_error("fork", 0);
	if (proc[0].pid == 0)
	{
		close_all_fds(1, proc_cnt - 1, proc);
		child_process(proc[0].fd, argv[1], argv[2], env);
	}
	close(proc[0].fd[1]);
}

void	nth_process(int n, t_process *proc, int proc_cnt, t_arg_info *arg_info)
{
	char	**exec_argv;

	proc[n].pid = fork();
	if (proc[n].pid == -1)
		print_error("fork", 0);
	if (proc[n].pid == 0)
	{
		close(proc[n].fd[0]);
		close_all_fds(n + 1, proc_cnt, proc);
		redirect_input_output(proc[n - 1].fd[0], proc[n].fd[1]);
		exec_argv = get_exec_argv(n, arg_info);
		execve(exec_argv[0], exec_argv, arg_info->env);
		perror(exec_argv[0]);
		exit(1);
	}
	if (n != proc_cnt - 1)
	{
		close(proc[n - 1].fd[0]);
		close(proc[n].fd[1]);
	}
}
