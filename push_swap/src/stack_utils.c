/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:56:47 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/05 23:41:15 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_stack_nth_idx(t_stack *stack, int n)
{
	int	idx;

	if (n > stack->size - 1)
		return (-1);
	idx = stack->head;
	while (n > 0)
	{
		if (idx == stack->size - 1)
			idx = 0;
		else
			++idx;
		--n;
	}
	return (n);
}

int	get_stack_next_idx(t_stack *stack, int curr)
{
	int	next;

	if (curr == stack->tail)
		next = stack->head;
	else if (curr == stack->size - 1)
		next = 0;
	else
		next = curr + 1;
	return (next);
}

int	get_stack_idx(t_stack *stack, int num)
{
	int	i;
	int	idx;

	i = stack->head;
	idx = 0;
	while (get_stack_next_idx(stack, i) != stack->head)
	{
		if (stack->data[i] == num)
			return (idx);
		i = get_stack_next_idx(stack, i);
		idx++;
	}
	return (-1);
}

void	rotate_to_top(t_stack *stack, int idx)
{
	if (idx > stack->size / 2)
		idx -= stack->cnt;
	if (idx < 0)
	{
		while (idx < 0)
		{
			rule_reverse_rotate(stack, "rra");
			idx++;
		}
	}
	else
	{
		while (idx > 0)
		{
			rule_rotate(stack, "ra");
			idx--;
		}
	}
}

void	swap_with_rotate(t_stack *a, int i)
{
	if (i > a->size / 2)
		i -= a->cnt;
	if (i < 0)
	{
		while (i < 0)
		{
			rule_reverse_rotate(a, "rra");
			i++;
		}
	}
	else
	{
		while (i > 0)
		{
			rule_rotate(a, "ra");
			i--;
		}
	}
	rule_swap(a, "sa");
}
