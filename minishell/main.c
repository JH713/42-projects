/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:33:01 by jihyeole          #+#    #+#             */
/*   Updated: 2023/05/15 21:07:27 by jihyeole         ###   ########.fr       */
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
	t_redirect	*re;
	(void)command;
	(void)env_lst;

	re = (t_redirect *)malloc(sizeof(t_redirect) * 3);
	re[0].file = ft_strdup("EOF");
	re[1].file = ft_strdup("END");
	re[2].file = ft_strdup("abc");
	re[0].type = 1;
	re[1].type = 1;
	re[2].type = 2;
	re[0].next = &re[1];
	re[1].next = NULL;
	re[2].next = NULL;
	info = (t_info *)malloc(sizeof(t_info));
	info->process_num = 2;
	info->heredoc_num = 3;
	info->commands = (t_command *)malloc(sizeof(t_command) * 2);
	info->commands[0].command = NULL;
	info->commands[1].command = NULL;
	info->commands[0].output = NULL;
	info->commands[1].output = NULL;
	info->commands[0].input = &re[0];
	info->commands[1].input = &re[2];
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
	while (i < process_cnt)
	{
		process[i].n = i;
		if (pipe(process[i].fd) == -1)
			print_error("pipe", 0);
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
		unlink_heredocs(comm_info);
		process = (t_process *)malloc(sizeof(process) * comm_info->process_num);
		create_pipe(process, comm_info->process_num);
		//프로세스 실행
	}
}
