/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_to_a_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:32:46 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/05 23:41:04 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	least_rules_process(t_stack *a, t_stack *b, int *process_ab)
{
	int	i;
	int	j;
	int	min;
	int	temp;

	min = 2147483647;
	i = 0;
	j = b->head;
	while (i < b->cnt)
	{
		temp = ft_abs(process_b(b, i)) + ft_abs(process_a(a, b->data[j]));
		if (temp < min)
		{
			min = temp;
			process_ab[0] = process_a(a, b->data[j]);
			process_ab[1] = process_b(b, i);
		}
		i++;
		if (j == b->size - 1)
			j = 0;
		else
			j++;
	}
}

static void	process_rotate(t_stack *stack, int i, char ab)
{
	if (i < 0)
	{
		while (i < 0)
		{
			if (ab == 'a')
				rule_reverse_rotate(stack, "rra");
			else if (ab == 'b')
				rule_reverse_rotate(stack, "rrb");
			i++;
		}
	}
	else
	{
		while (i > 0)
		{
			if (ab == 'a')
				rule_rotate(stack, "ra");
			else if (ab == 'b')
				rule_rotate(stack, "rb");
			i--;
		}
	}
}

static void	run_rules(t_stack *a, t_stack *b, int *process_ab)
{
	process_rotate(a, process_ab[0], 'a');
	process_rotate(b, process_ab[1], 'b');
	rule_push(b, a, "pa");
}

void	push_b_to_a(t_stack *a, t_stack *b)
{
	int	i;
	int	process_ab[2];

	i = 0;
	while (i < b->size)
	{
		if (i <= 1)
			rule_push(b, a, "pa");
		else
		{
			least_rules_process(a, b, process_ab);
			run_rules(a, b, process_ab);
		}
		i++;
	}
}
