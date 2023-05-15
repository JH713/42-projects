/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 20:32:17 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/14 08:40:22 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_process
{
	pid_t	pid;
	int		fd[2];
	int		n;
}	t_process;

typedef struct s_arg_info
{
	char	**argv;
	char	**env;
}	t_arg_info;

void	heredoc_first_process(t_process *process, int process_cnt, char *end);
void	first_process(t_process *proc, int proc_cnt, char **argv, char **env);
void	nth_process(int n, t_process *proc, int proc_cnt, t_arg_info *arg_info);
void	parent(int fds[2], char *file, char *cmd, char **env);
void	hd_parent(int fds[2], char *file, char *cmd, char **env);
void	parent_process(t_process *process, int argc, char **argv, char **env);
char	**get_path(char **env);
char	*check_path(char **env, char *cmd);
char	**get_exec_argv(int n, t_arg_info *arg_info);
void	print_error(char *msg, int status);
void	redirect_input_output(int input, int output);
void	create_pipe(t_process *process, int process_cnt);
void	close_all_fds(int start, int end, t_process *process);
void	wait_all_child(int process_cnt, t_process *process);

#endif