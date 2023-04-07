/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_head_tail_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 23:45:27 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/05 23:45:44 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	move_next_head(t_stack *stack)
{
	if (stack->head == stack->size - 1)
		stack->head = 0;
	else
		stack->head++;
}

void	move_prev_head(t_stack *stack)
{
	if (stack->head == 0)
		stack->head = stack->size - 1;
	else
		stack->head--;
}

void	move_next_tail(t_stack *stack)
{
	if (stack->tail == stack->size - 1)
		stack->tail = 0;
	else
		stack->tail++;
}

void	move_prev_tail(t_stack *stack)
{
	if (stack->tail == 0)
		stack->tail = stack->size - 1;
	else
		stack->tail--;
}
