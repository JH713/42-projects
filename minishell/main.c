/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 22:00:08 by jihyeole          #+#    #+#             */
/*   Updated: 2023/05/12 23:20:40 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*command;

char	**get_path(char **env)
{
	char	**path;
	int		i;
	char	*temp;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		++i;
	if (env[i])
		path = ft_split(&env[i][5], ':');
	else
		path = NULL;
	i = 0;
	while (path[i])
	{
		temp = path[i];
		path[i] = ft_strjoin(path[i], "/");
		free(temp);
		++i;
	}
	return (path);
}

char	*execute_check(char *command, char **path)
{
	int		i;
	char	*full_path;

	if (command[0] == '.' || command[0] == '/')
	{
		if (access(command, X_OK) != 0)
		{
			minishell_perror(command);
			return (NULL);
		}
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
	minishell_err_msg(command, "command not found");
	return (NULL);
}

void	print_env(char **env, int env_num)
{
	int	i;

	i = 0;
	while (i < env_num)
	{
		if (env[i])
			ft_putendl_fd(env[i], 1);
		++i;
	}
}

void	ft_putendl_stdout(void *s)
{
	ft_putendl_fd((char *)s, 1);
}

void	ft_env_lst_unset(t_list **head, char *unset_str)
{
	t_list	*lst;
	t_list	*prev;

	lst = *head;
	int unset_str_len = ft_strlen(unset_str);
	if (*head == NULL)
		return ;
	while (lst)
	{
		if (ft_strncmp(lst->content, unset_str, unset_str_len) == 0)
		{
			ft_lstdelone(lst, free);
			if (lst == *head)
				*head = NULL;
			else
				prev->next = lst->next;
			break ;
		}
		prev = lst;
		lst = lst->next;
	}
}

char	*get_key(char *command)
{
	char	*key;
	int i = 0;
	while (command[i] != '=')
		++i;
	key = ft_substr(command, 0, i + 1);
	return (key);
}

int builtin_func(char *command, char **env, int env_num, t_list **env_head)
{
	int	i;

	if (ft_strncmp(command, "exit", 5) == 0)
	{
		ft_printf("exit\n");
		free(command);
		exit(0);
	}
	else if (ft_strncmp(command, "env", 4) == 0)
	{
		print_env(env, env_num);
		free(command);
		ft_lstiter(*env_head, ft_putendl_stdout);
		return (1);
	}
	else if (ft_strncmp(command, "export ", 7) == 0)
	{
		t_list *new_env;
		char *key = get_key(&command[7]);
		int flag = 0;
		i = 0;
		while (i < env_num)
		{
			if (env[i] == NULL)
				continue ;
			if (ft_strncmp(env[i], key, ft_strlen(key)) == 0)
			{
				env[i] = ft_strdup(&command[7]);
				flag = 1;
				break ;
			}
			++i;
		}
		free (key);
		if (flag)
		{
			free(command);
			return (1);
		}
		new_env = ft_lstnew(ft_strdup(&command[7]));
		ft_lstadd_front(env_head, new_env);
		free(command);
		return (1);
	}
	else if (ft_strncmp(command, "unset ", 6) == 0)
	{
		i = 0;
		char *unset_str = ft_strjoin(&command[6], "=");
		int	unset_str_len = ft_strlen(unset_str);
		while (i < env_num)
		{
			if (env[i] == NULL)
				continue ;
			if (ft_strncmp(env[i], unset_str, unset_str_len) == 0)
			{
				env[i] = NULL;
				break ;
			}
			++i;
		}
		ft_env_lst_unset(env_head, unset_str);
		free(unset_str);
		free(command);
		return (1);
	}
	else if (ft_strncmp(command, "pwd", 4) == 0)
	{
		char *buf = NULL;
		buf = getcwd(buf, 0);
		ft_printf("%s\n", buf);
		free(buf);
		free(command);
		return (1);
	}
	else if (ft_strncmp(command, "cd ", 3) == 0)
	{
		int ret;
		if (command[3] == '/' || command[3] == '.')
			ret = chdir(&command[3]);
		else
		{
			char *f_path = 0;
			char *buf = NULL;
			buf = getcwd(buf, 0);
			f_path = ft_strjoin(buf, "/");
			free(buf);
			buf = f_path;
			f_path = ft_strjoin(buf, &command[3]);
			free(buf);
			ret = chdir(f_path);
			free(f_path);
		}
		if (ret == -1)
			minishell_perror("cd");
		free(command);
		return (1);
	}
	else if (ft_strncmp(command, "echo -n ", 8) == 0)
	{
		ft_printf("%s", &command[8]);
		return (1);
	}
	return (0);
}

void	sigint_handler(int signo, siginfo_t *info, void *p)
{
	(void)signo;
	(void)info;
	(void)p;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

int	main(int argc, char **argv, char **env)
{
	char	**path;
	char	*full_path;
	t_list	*env_head;
	int		env_num;
	struct sigaction	sigint_act;
	// struct sigaction	act2;

	(void)argv;
	if (argc != 1)
		print_error_with_exit("Error: Invalid number of arguments.");
	path = get_path(env);
	env_head = NULL;
	env_num = 0;
	while (env[env_num])
		env_num++;
	sigint_act.sa_sigaction = sigint_handler;
	sigint_act.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &sigint_act, NULL);
	while (1)
	{
		command = readline("minishell$ ");
		if (command == NULL)
		{
			free(command);
			ft_putstr_fd("\x1b[1A", 1);
			ft_putstr_fd("\033[11C", 1);
			write(1, "exit\n", 5);
			break ;
		}
		if (ft_strlen(command) != 0)
			add_history(command);
		if (builtin_func(command, env, env_num, &env_head) == 1)
			continue ;
		full_path = execute_check(command, path);
		if (full_path == NULL)
			continue ;
		ft_printf("%s\n", full_path);
		free(full_path);
		free(command);
	}
}
