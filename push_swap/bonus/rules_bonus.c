/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 03:38:46 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/05 04:40:23 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rule_swap(t_stack *stack)
{
	int	temp;
	int	next_idx;

	if (stack->head < 0 || stack->head == stack->tail)
		return ;
	temp = stack->data[stack->head];
	if (stack->head == stack->size - 1)
		next_idx = 0;
	else
		next_idx = stack->head + 1;
	stack->data[stack->head] = stack->data[next_idx];
	stack->data[next_idx] = temp;
}

void	rule_push(t_stack *from, t_stack *to)
{
	int	temp;

	if (from->head < 0)
		return ;
	temp = from->data[from->head];
	if (from->head == from->tail)
		from->head = -1;
	else
		move_next_head(from);
	if (to->head < 0)
	{
		to->head = 0;
		to->tail = 0;
	}
	else
		move_prev_head(to);
	to->data[to->head] = temp;
	from->cnt--;
	to->cnt++;
}

void	rule_rotate(t_stack *stack)
{
	int	temp;

	if (stack->head < 0 || stack->head == stack->tail)
		return ;
	temp = stack->data[stack->head];
	move_next_head(stack);
	move_next_tail(stack);
	stack->data[stack->tail] = temp;
}

void	rule_reverse_rotate(t_stack *stack)
{
	int	temp;

	if (stack->head < 0 || stack->head == stack->tail)
		return ;
	move_prev_head(stack);
	temp = stack->data[stack->tail];
	move_prev_tail(stack);
	stack->data[stack->head] = temp;
}

void	rule_a_and_b(t_stack *a, t_stack *b, int i)
{
	if (i == 0)
	{
		rule_swap(a);
		rule_swap(b);
	}
	else if (i == 1)
	{
		rule_rotate(a);
		rule_rotate(b);
	}
	else if (i == 2)
	{
		rule_reverse_rotate(a);
		rule_reverse_rotate(b);
	}
}
