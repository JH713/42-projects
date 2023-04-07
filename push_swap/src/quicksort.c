/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:12:01 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/05 23:41:08 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	partition(int *data, int start, int end)
{
	int	pivot;
	int	left;
	int	right;

	pivot = data[end];
	left = start;
	right = end - 1;
	while (1)
	{
		while (data[left] <= pivot && left != end)
			left++;
		while (data[right] >= pivot && right != 0)
			right--;
		if (right < left || left == end || left == right)
			break ;
		swap(&data[left], &data[right]);
	}
	swap(&data[left], &data[end]);
	return (left);
}

void	quicksort(int *data, int start, int end)
{
	int	pivot_idx;

	if (end - start < 1)
		return ;
	pivot_idx = partition(data, start, end);
	quicksort(data, start, pivot_idx - 1);
	quicksort(data, pivot_idx + 1, end);
}
