/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 07:57:10 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/14 07:58:08 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	print_error(char *msg, int status)
{
	if (status == 0)
		perror(msg);
	else if (status == 1)
		ft_putendl_fd(msg, 2);
	exit(1);
}

void	redirect_input_output(int input, int output)
{
	close(0);
	dup2(input, 0);
	close(input);
	close(1);
	dup2(output, 1);
	close(output);
}

void	create_pipe(t_process *process, int process_cnt)
{
	int	i;

	i = 0;
	while (i < process_cnt)
	{
		process[i].n = i;
		if (pipe(process[i].fd) == -1)
			print_error("pipe", 0);
		++i;
	}
}

void	close_all_fds(int start, int end, t_process *process)
{
	while (start <= end)
	{
		close(process[start].fd[0]);
		close(process[start].fd[1]);
		++start;
	}
}

void	wait_all_child(int process_cnt, t_process *process)
{
	int	i;
	int	status;

	i = 0;
	while (i < process_cnt)
	{
		waitpid(process[i].pid, &status, 0);
		++i;
	}
}
