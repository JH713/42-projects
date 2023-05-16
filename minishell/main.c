/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:33:01 by jihyeole          #+#    #+#             */
/*   Updated: 2023/05/16 21:07:10 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*read_command(void)
{
	char	*command;

	command = readline("minishell$ ");
	if (command == NULL)
	{
		free(command);
		ft_putstr_fd("\x1b[1A", 1);
		ft_putstr_fd("\033[11C", 1);
		write(1, "exit\n", 5);
		exit(0);
	}
	if (ft_strlen(command) != 0)
		add_history(command);
	return (command);
}

t_info	*parse_command(char *command, t_env *env_lst)
{
	// 파싱 구현
	// syntax error NULL 반환 
	t_info *info;
	// t_redirect	*re;
	(void)command;
	(void)env_lst;
	char	**commands;
	char	**commands1;

	// re = (t_redirect *)malloc(sizeof(t_redirect) * 3);
	// re[0].file = ft_strdup("EOF");
	// re[1].file = ft_strdup("END");
	// re[2].file = ft_strdup("abc");
	// re[0].type = 1;
	// re[1].type = 1;
	// re[2].type = 2;
	// re[0].next = &re[1];
	// re[1].next = NULL;
	// re[2].next = NULL;
	info = (t_info *)malloc(sizeof(t_info));
	info->process_num = 2;
	info->heredoc_num = 0;
	commands = (char **)malloc(sizeof(char *) * 2);
	commands[0] = ft_strdup("ls");
	commands[1] = NULL;
	commands1 = (char **)malloc(sizeof(char *) * 2);
	commands1[0] = ft_strdup("wc");
	commands1[1] = NULL;
	info->commands = (t_command *)malloc(sizeof(t_command) * 2);
	info->commands[0].command = commands;
	info->commands[0].output = NULL;
	info->commands[0].input = NULL;
	info->commands[1].command = commands1;
	info->commands[1].output = NULL;
	info->commands[1].input = NULL;
	// t_redirect *input = info->commands[0].input;
	// ft_printf("%s\n", input->file);
	// ft_printf("%s\n", input->next->file);
	return (info);
}

int	unlink_heredocs(t_info *comm_info)
{
	int	i;

	i = 0;
	while (comm_info->heredocs[i])
	{
		unlink(comm_info->heredocs[i]);
		++i;
	}
	return (0);
}

void	create_pipe(t_process *process, int process_cnt)
{
	int	i;

	i = 0;
	while (i < process_cnt -1)
	{
		// process[i].n = i;
		if (pipe(process[i].fd) == -1)
			print_error("pipe", 0);
		++i;
	}
	// process[i].n = i;
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

int	fd_check(char *fd)
{
	int	fd_num;

	if (ft_strlen(fd) > 3)
		minishell_error(fd, strerror(9));
	fd_num = ft_atoi(fd);
	if (fd_num >= 256)
		minishell_error(fd, strerror(9));
	return (fd_num);
}

void	redirect_input(t_process *proc, t_redirect *input)
{
	int		fd;
	int		input_fd;
	char	*filepath;

	if (proc->n != 0)
	{
		close(0);
		dup2(proc[proc->n - 1].fd[0], 0);
		close(proc[proc->n - 1].fd[0]);
	}
	while (input)
	{
		input_fd = fd_check(input->fd);
		if (input->type == 0 || input->type == 1 || input->type == 2)
		{
			if (input->file[0] != '/')
				filepath = ft_strjoin("./", input->file);
			else
				filepath = ft_strdup(input->file);
			fd = open(filepath, O_RDONLY);
			if (fd == -1)
				minishell_perror(input->file);
			free(filepath);
			close(input_fd);
			dup2(fd, input_fd);
			close(fd);
		}
		else
			print_error("input type error", 1);
		input = input->next;
	}
}

void	redirect_output(t_process *proc, t_redirect *output, int process_num)
{
	int		fd;
	int		output_fd;
	char	*filepath;

	if (proc->n != process_num - 1)
	{
		close(1);
		dup2(proc[proc->n].fd[1], 1);
		close(proc[proc->n].fd[1]);
	}
	while (output)
	{
		output_fd = fd_check(output->fd);
		if (output->type == 0 || output->type == 1)
		{
			if (output->file[0] != '/')
				filepath = ft_strjoin("./", output->file);
			else
				filepath = ft_strdup(output->file);
			if (output->type == 0)
				fd = open(filepath, O_WRONLY | O_CREAT | O_TRUNC, 0644);
			else
				fd = open(filepath, O_WRONLY | O_CREAT | O_APPEND, 0644);
			if (fd == -1)
				minishell_perror(output->file);
			free(filepath);
			close(output_fd);
			dup2(fd, output_fd);
			close(fd);
		}
		else
			print_error("input type error", 1);
		output = output->next;
	}
}

char	*execute_check(char *command, char **path)
{
	int		i;
	char	*full_path;

	if (command[0] == '.' || command[0] == '/')
	{
		if (access(command, X_OK) != 0)
			minishell_perror(command);
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
	minishell_error(command, "command not found");
	return (NULL);
}

void	redirect_process(t_process *proc, t_command *comm, int process_num)
{
	redirect_input(proc, comm->input);
	redirect_output(proc, comm->output, process_num);
}

int	env_lst_size(t_env *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		++size;
	}
	return (size);
}

char	*get_env_str(t_env *env_lst)
{
	char	*temp;
	char	*env_str;

	if (env_lst == NULL)
		return (NULL);
	temp = ft_strjoin(env_lst->key, "=");
	env_str = ft_strjoin(temp, env_lst->value);
	free(temp);
	return (env_str);
}

char	**env_lst_to_arr(t_env *env_lst)
{
	int		i;
	char	**env;

	env = (char **)malloc(sizeof(char *) * (env_lst_size(env_lst) + 1));
	i = 0;
	while (env_lst)
	{
		env[i] = get_env_str(env_lst);
		env_lst = env_lst->next;
		++i;
	}
	env[i] = NULL;
	return (env);
}

void	fork_and_execute(t_process *proc, t_info *info, t_env *env_lst)
{
	int		i;
	char	**path;
	char	*full_path;
	char	**env;

	i = 0;
	path = get_path(env_lst);
	while (i < info -> process_num)
	{
		proc[i].pid = fork();
		if (proc[i].pid == -1)
			print_error("fork", 0);
		if (proc[i].pid == 0)
		{
			close_all_fds(i + 1, info->process_num - 2, proc);
			if (i < info->process_num - 1)
				close(proc[i].fd[0]);
			redirect_process(&proc[i], &info->commands[i], info->process_num);
			full_path = execute_check(info->commands[i].command[0], path);
			free(info->commands[i].command[0]);
			info->commands[i].command[0] = full_path;
			env = env_lst_to_arr(env_lst);
			execve(info->commands[i].command[0], info->commands[i].command, env);
			perror(info->commands[i].command[0]);
			exit(1);
		}
		if (i == 0)
			close(proc[0].fd[1]);
		else if (i == info -> process_num - 1)
			break ;
		else
		{
			close(proc[i - 1].fd[0]);
			close(proc[i].fd[1]);
		}
		++i;
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

int	main(int argc, char *argv[], char **env)
{
	t_env		*env_lst;
	char		*command;
	t_info		*comm_info;
	t_process	*process;

	init(argc, argv, env, &env_lst);
	while (1)
	{
		command = read_command();
		comm_info = parse_command(command, env_lst);
		if (comm_info == NULL)
			continue ;
		if (create_heredoc_temp(comm_info, env_lst) == 0)
			continue ;
		process = (t_process *)malloc(sizeof(t_process) * comm_info->process_num);
		create_pipe(process, comm_info->process_num);
		int	i = 0;
		while (i < comm_info->process_num)
		{
			process[i].n = i;
			++i;
		}
		fork_and_execute(process, comm_info, env_lst);
		wait_all_child(comm_info->process_num, process);
		unlink_heredocs(comm_info);
	}
}
