/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 22:01:25 by jihyeole          #+#    #+#             */
/*   Updated: 2023/05/15 21:04:49 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_redirect
{
	int					fd;
	int					type;
	char				*file;
	struct s_redirect	*next;
}	t_redirect;

typedef struct s_command
{
	char				**command;
	t_redirect			*input;
	t_redirect			*output;
}	t_command;

typedef struct s_info
{
	int			process_num;
	int			heredoc_num;
	char		**heredocs;
	t_command	*commands;
}	t_info;

typedef struct s_process
{
	pid_t	pid;
	int		fd[2];
	int		n;
}	t_process;

void	init(int argc, char *argv[], char **env, t_env **env_lst);
int		get_first_idx(char *str, char c);
char	**get_path(char **env);
void	env_lst_add_back(t_env **lst, t_env *new);
t_env	*env_lst_new(char *env);
void	print_env(char **env, int env_num);
void	minishell_error(char *command, char *err_msg);
void	minishell_perror(char *msg);
int		unlink_heredocs(t_info *comm_info);
int		create_heredoc_temp(t_info *info, t_env *env_lst);
char	*get_env_value(t_env *env_lst, char *key);
void	join_env(char **line, char *env_value, int start, int end);
void	expand_env(char **line, t_env *env_lst);

#endif
