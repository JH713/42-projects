/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:16:09 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/05 23:41:14 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	stack_size_4(t_stack *a)
{
	int	i;
	int	j;
	int	cnt;
	int	*data;

	i = a->head;
	j = -1;
	cnt = 0;
	data = a->data;
	while (j != a->head)
	{
		j = get_stack_next_idx(a, i);
		if (data[i] - data[j] == 1 || (data[i] == 0 && data[j] == 3))
		{
			swap_with_rotate(a, cnt);
			i = a->head;
			cnt = 0;
			continue ;
		}
		i = get_stack_next_idx(a, i);
		cnt++;
	}
	rotate_to_top(a, get_stack_idx(a, 0));
}

static void	stack_size_4_for_5(t_stack *a)
{
	int	i;
	int	j;
	int	cnt;
	int	*data;

	i = a->head;
	j = -1;
	cnt = 0;
	data = a->data;
	while (j != a->head)
	{
		j = get_stack_next_idx(a, i);
		if (data[i] - data[j] == 1 || (data[i] == 1 && data[j] == 4))
		{
			swap_with_rotate(a, cnt);
			i = a->head;
			cnt = 0;
			continue ;
		}
		i = get_stack_next_idx(a, i);
		cnt++;
	}
	rotate_to_top(a, get_stack_idx(a, 1));
}

static void	stack_size_3(t_stack *a)
{
	int	i;
	int	j;

	if (a->data[0] == 2)
	{
		rule_rotate(a, "ra");
	}
	else if (a->data[1] == 2)
	{
		rule_reverse_rotate(a, "rra");
	}
	i = a->head;
	if (i == a->size - 1)
		j = 0;
	else
		j = i + 1;
	if (a->data[i] > a->data[j])
	{
		rule_swap(a, "sa");
	}
	return ;
}

static void	stack_size_5(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (a->data[i] != 0)
		++i;
	rotate_to_top(a, i);
	rule_push(a, b, "pb");
	stack_size_4_for_5(a);
	rule_push(b, a, "pa");
}

void	small_stack(t_stack *a, t_stack *b)
{
	if (a->size == 1)
		return ;
	else if (a->size == 2)
	{
		if (a->data[0] > a->data[1])
		{
			rule_swap(a, "sa");
			return ;
		}
	}
	else if (a->size == 3)
		stack_size_3(a);
	else if (a->size == 4)
		stack_size_4(a);
	else if (a->size == 5)
		stack_size_5(a, b);
}
