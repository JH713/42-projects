/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:33:01 by jihyeole          #+#    #+#             */
/*   Updated: 2023/05/17 22:35:43 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*read_command(void)
{
	char	*command;

	command = readline("minishell$ ");
	if (command == NULL)
	{
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
	// char	**commands;
	// char	**commands1;
	// char	**commands2;

	// re = (t_redirect *)malloc(sizeof(t_redirect) * 1);
	// re[0].file = ft_strdup("EOF");
	// // re[1].file = ft_strdup("END");
	// // re[2].file = ft_strdup("abc");
	// re[0].type = 1;
	// re[0].fd = NULL;
	// // re[1].type = 1;
	// // re[2].type = 2;
	// re[0].next = NULL;
	// re[1].next = NULL;
	// re[2].next = NULL;
	info = (t_info *)malloc(sizeof(t_info));
	info->process_num = 1;
	info->heredoc_num = 0;
	// commands = ft_split(command, ' ');
	info->commands = (t_command *)malloc(sizeof(t_command) * 1);
	info->commands[0].command = ft_split(command, ' ');
	info->commands[0].output = NULL;
	info->commands[0].input = NULL;
	// info->commands[1].command = ft_split("wc", ' ');
	// info->commands[1].output = NULL;
	// info->commands[1].input = NULL;
	// info->commands[2].command = ft_split("cat", ' ');
	// info->commands[2].output = NULL;
	// info->commands[2].input = NULL;
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
	while (i < process_cnt - 1)
	{
		process[i].n = i;
		if (pipe(process[i].fd) == -1)
			print_error("pipe", 0);
		++i;
	}
	process[i].n = i;
}

void	close_unused_pipes(int start, int end, t_process *process)
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

int	builtin_func(char **command, t_env **env_lst)
{
	char	**env;
	int		env_num;

	env = env_lst_to_arr(*env_lst);
	env_num = env_lst_size(*env_lst);
	if (ft_strncmp(command[0], "exit", 5) == 0 && command[1] == NULL)
		exit(0);
	else if (ft_strncmp(command[0], "env", 4) == 0 && command[1] == NULL)
	{
		print_env(env, env_num);
		return (1);
	}
	else if (ft_strncmp(command[0], "export", 7) == 0 && command[1])
	{
		get_env_lst(env_lst, &command[1]);
		return (1);
	}
	else if (ft_strncmp(command[0], "unset", 6) == 0 && command[1])
	{
		env_lst_unset(env_lst, &command[1]);
		return (1);
	}
	else if (ft_strncmp(command[0], "pwd", 4) == 0 && command[1] == NULL)
	{
		char	*buf = NULL;
		buf = getcwd(buf, 0);
		ft_printf("%s\n", buf);
		free(buf);
		return (1);
	}
	else if (ft_strncmp(command[0], "cd", 3) == 0)
	{
		int ret;
		if (command[1] == NULL)
		{
			t_env *lst;
			lst = get_lst_by_key(*env_lst, "HOME");
			if (lst == NULL)
			{
				ft_putendl_fd("minishell: cd: HOME path not found", 2);
				return (1);
			}
			ret = chdir(lst->value);
		}
		else if (command[1][0] == '/' || command[1][0] == '.')
			ret = chdir(command[1]);
		else
		{
			char *full_path = NULL;
			full_path = ft_strjoin("./", command[1]);
			ret = chdir(full_path);
			free(full_path);
		}
		if (ret == -1)
		{
			ft_putstr_fd("minishell: ", 2);
			perror("cd");
		}
		return (1);
	}
	else if (ft_strncmp(command[0], "echo", 5) == 0 && ft_strncmp(command[1], "-n", 3) == 0)
	{
		if (command[2] != NULL)
			ft_printf("%s", command[2]);
		return (1);
	}
	return (0);
}

void	fork_and_execute(t_process *proc, t_info *info, t_env **env_lst)
{
	int		i;
	char	**path;
	char	*full_path;
	char	**env;
	char	**command;

	i = 0;
	path = get_path(*env_lst);
	while (i < info -> process_num)
	{
		proc[i].pid = fork();
		if (proc[i].pid == -1)
			print_error("fork", 0);
		if (proc[i].pid == 0)
		{
			close_unused_pipes(i + 1, info->process_num - 2, proc);
			if (i < info->process_num - 1)
				close(proc[i].fd[0]);
			redirect_process(proc, info, i);
			command = info->commands[i].command;
			if (builtin_func(command, env_lst))
				exit (0);
			full_path = execute_check(command[0], path);
			free(command[0]);
			command[0] = full_path;
			env = env_lst_to_arr(*env_lst);
			execve(command[0], command, env);
			perror(command[0]);
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

int	exec_single_builtin(t_info *info, t_env **env_lst)
{
	char	**path;
	char	**command;

	path = get_path(*env_lst);
	redirect_process(NULL, info, 0);
	command = info->commands[0].command;
	return (builtin_func(command, env_lst));
}

int	main(int argc, char *argv[], char **env)
{
	t_env		*env_lst;
	char		*command;
	t_info		*info;
	t_process	*process;

	init(argc, argv, env, &env_lst);
	while (1)
	{
		command = read_command();
		if (ft_strncmp(command, "", 1) == 0) //나중에 parse에서 처리 
			continue ;
		info = parse_command(command, env_lst);
		if (info == NULL)
			continue ;
		if (create_heredoc_temp(info, env_lst) == 0)
			continue ;
		if (info->process_num == 1)
		{
			if (exec_single_builtin(info, &env_lst))
			{
				unlink_heredocs(info);
				continue ;
			}
		}
		process = (t_process *)malloc(sizeof(t_process) * info->process_num);
		create_pipe(process, info->process_num);
		fork_and_execute(process, info, &env_lst);
		wait_all_child(info->process_num, process);
		unlink_heredocs(info);
	}
}
