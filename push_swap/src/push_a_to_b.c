/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 00:51:26 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/05 23:41:01 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	get_pivots(t_stack *a, t_pivots *pivots)
{
	pivots->left_pivot = a->size / 3;
	if (a->size % 3 == 0)
		pivots->right_pivot = (a->size / 3) * 2;
	else
		pivots->right_pivot = (a->size / 3) * 2 + 1;
}

void	push_a_to_b(t_stack *a, t_stack *b)
{
	t_pivots	pivots;
	int			idx;

	get_pivots(a, &pivots);
	idx = 0;
	while (idx < a->size)
	{
		if (a->data[a->head] < pivots.left_pivot)
			rule_rotate(a, "ra");
		else if (a->data[a->head] < pivots.right_pivot)
			rule_push(a, b, "pb");
		else
		{
			rule_push(a, b, "pb");
			rule_rotate(b, "rb");
		}
		idx++;
	}
	while (a-> head >= 0)
		rule_push(a, b, "pb");
}
