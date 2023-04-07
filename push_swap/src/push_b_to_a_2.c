/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_to_a_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:34:35 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/05 23:41:06 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	num_position_to_a(t_stack *a, int num)
{
	int	i;
	int	j;
	int	boundary;
	int	next;

	i = 0;
	j = a->head;
	while (i < a->cnt)
	{
		next = a->data[get_stack_next_idx(a, j)];
		if (num > a->data[j] && num < next)
			return (i + 1);
		if (a->data[j] > next)
			boundary = i + 1;
		i++;
		if (j == a->size - 1)
			j = 0;
		else
			j++;
	}
	return (boundary);
}

int	process_a(t_stack *a, int num)
{
	int	pos;

	pos = num_position_to_a(a, num);
	if (pos > a->cnt / 2)
		pos -= a->cnt;
	return (pos);
}

int	process_b(t_stack *b, int i)
{
	if (i > b->cnt / 2)
		i -= b->cnt;
	return (i);
}
