/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 20:26:46 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/06 05:32:17 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

static void	free_data(t_stack *a, t_stack *b)
{
	free(a->data);
	free(b->data);
}

static void	change_a(t_stack *a)
{
	int	*sorted_data;
	int	i;

	sorted_data = dup_data(a);
	quicksort(sorted_data, 0, a->size - 1);
	i = 0;
	while (i < a->size)
	{
		a->data[i] = get_idx(sorted_data, a->data[i]);
		++i;
	}
	free(sorted_data);
}

static int	is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size - 1)
	{
		if (a->data[i + 1] < a->data[i])
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		return (0);
	init_a(&a, argv);
	init_b(&b, a.size);
	if (is_sorted(&a))
	{
		free_data(&a, &b);
		return (0);
	}
	change_a(&a);
	if (a.size < 6)
	{
		small_stack(&a, &b);
		free_data(&a, &b);
		return (0);
	}
	push_a_to_b(&a, &b);
	push_b_to_a(&a, &b);
	rotate_to_top(&a, get_stack_idx(&a, 0));
	free_data(&a, &b);
}
