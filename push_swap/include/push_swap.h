/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 20:27:36 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/05 23:35:58 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct s_stack
{
	int	*data;
	int	head;
	int	tail;
	int	size;
	int	cnt;
}	t_stack;

typedef struct s_pivots
{
	int	left_pivot;
	int	right_pivot;
}	t_pivots;

void	init_a(t_stack *a, char **argv);
void	init_b(t_stack *b, int argc);

void	push_args_to_a(t_stack *a, char **argv);

int		check_num(char *num);
int		is_integer(char *num);
int		is_duplicate(int *a, int i, int num);

void	rule_swap(t_stack *stack, char *command);
void	rule_rotate(t_stack *stack, char *command);
void	rule_reverse_rotate(t_stack *stack, char *command);
void	rule_push(t_stack *from, t_stack *to, char *command);
void	move_next_head(t_stack *stack);
void	move_prev_head(t_stack *stack);
void	move_next_tail(t_stack *stack);
void	move_prev_tail(t_stack *stack);
void	swap(int *a, int *b);
int		*dup_data(t_stack *a);
int		get_idx(int *data, int num);
void	quicksort(int *data, int start, int end);
void	get_pivots(t_stack *a, t_pivots *pivots);
void	push_a_to_b(t_stack *a, t_stack *b);
int		ft_abs(int num);
int		check_num(char *num);
int		is_integer(char *num);
int		is_duplicate(int *a, int i, int num);
void	quicksort(int *data, int start, int end);
int		print_error(void);
int		get_stack_idx(t_stack *stack, int num);
int		get_stack_next_idx(t_stack *stack, int curr);
int		get_stack_nth_idx(t_stack *stack, int n);
void	small_stack(t_stack *a, t_stack *b);
void	rotate_to_top(t_stack *stack, int idx);
void	swap_with_rotate(t_stack *a, int i);
void	push_b_to_a(t_stack *a, t_stack *b);
int		process_a(t_stack *a, int num);
int		process_b(t_stack *b, int i);

#endif