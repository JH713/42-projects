/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 03:39:11 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/06 00:31:14 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include "../libft/libft.h"

typedef struct s_stack
{
	int	*data;
	int	head;
	int	tail;
	int	size;
	int	cnt;
}	t_stack;

int		init_a(t_stack *a, char **argv);
void	init_b(t_stack *b, int arg_num);
void	rule_swap(t_stack *stack);
void	rule_push(t_stack *from, t_stack *to);
void	rule_rotate(t_stack *stack);
void	rule_reverse_rotate(t_stack *stack);
void	rule_a_and_b(t_stack *a, t_stack *b, int i);
void	move_next_head(t_stack *stack);
void	move_prev_head(t_stack *stack);
void	move_next_tail(t_stack *stack);
void	move_prev_tail(t_stack *stack);
void	put_num_to_a(t_stack *a, char **argv);
int		check_num(char *num);
int		is_integer(char *num);
int		is_duplicate(int *a, int i, int num);
int		print_error(void);
void	free_instructions(char **instructions);
char	*ft_strjoin_with_free(char *s1, char *s2);
int		cnt_new_line(const char *line);
int		get_stack_next_idx(t_stack *stack, int curr);

#endif