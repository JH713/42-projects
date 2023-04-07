/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 00:49:40 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/05 23:41:17 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	*dup_data(t_stack *a)
{
	int	*p;
	int	i;

	p = (int *)malloc(sizeof(int) * a->size);
	if (p == NULL)
		print_error();
	i = 0;
	while (i <= a->size)
	{
		p[i] = a->data[i];
		i++;
	}
	return (p);
}

int	ft_abs(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

int	get_idx(int *data, int num)
{
	int	i;

	i = 0;
	while (1)
	{
		if (data[i] == num)
			return (i);
		i++;
	}
}
