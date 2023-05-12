/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 22:01:25 by jihyeole          #+#    #+#             */
/*   Updated: 2023/05/12 23:06:47 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_redirect {
	int					fd;
	int					type;
	char				*file;
	struct s_redirect	*next;
}	t_redirect;

typedef struct s_command {
	char		*command;
	char		*executable;
	char		*remainder;
	t_redirect	*input;
	t_redirect	*output;
}	t_command;

void	minishell_err_msg(char *command, char *err_msg);
void	minishell_perror(char *msg);
void	print_error_with_exit(char *msg);

#endif
