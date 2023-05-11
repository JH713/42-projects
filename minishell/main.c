/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 22:00:08 by jihyeole          #+#    #+#             */
/*   Updated: 2023/05/11 20:04:05 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	main(int argc, char **argv, char **env)
{
	char	*command;
	char	**path;
	char	*full_path;
	t_list	*env_head;
	t_list	*new_env;
	int		env_num;
	int		i;

	(void)argv;
	if (argc != 1)
		print_error_with_exit("Error: Invalid number of arguments.");
	path = get_path(env);
	env_head = NULL;
	env_num = 0;
	while (env[env_num])
		env_num++;
	while (1)
	{
		command = readline("minishell$ ");
		if (ft_strlen(command) != 0)
			add_history(command);
		if (ft_strncmp(command, "exit", 5) == 0)
		{
			ft_printf("exit\n");
			free(command);
			break ;
		}
		else if (ft_strncmp(command, "env", 4) == 0)
		{
			print_env(env, env_num);
			free(command);
			ft_lstiter(env_head, ft_putendl_stdout);
			continue ;
		}
		else if (ft_strncmp(command, "export ", 7) == 0)
		{
			// env에서 export뒤에 key=찾아서 있으면 이 값으로 바꿔줘야함
			new_env = ft_lstnew(ft_strdup(&command[7]));
			ft_lstadd_front(&env_head, new_env);
			continue ;
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
			ft_env_lst_unset(&env_head, unset_str);
			free(unset_str);
			continue ;
		}
		full_path = execute_check(command, path);
		if (full_path == NULL)
			continue ;
		ft_printf("%s\n", full_path);
		free(full_path);
		free(command);
	}
}
