/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_args_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:09:59 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/05 23:41:03 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	check_and_push(char *str, t_stack *a, int a_idx)
{
	if (!is_integer(str) || is_duplicate(a->data, a_idx, ft_atoi(str)))
		print_error();
	a->data[a_idx] = ft_atoi(str);
}

static void	push_str_with_space(char *str, t_stack *a, int *a_idx)
{
	int		i;
	char	**strs;

	strs = ft_split(str, ' ');
	if (strs == NULL || *strs == NULL)
		print_error();
	i = 0;
	while (strs[i])
	{
		check_and_push(strs[i], a, *a_idx);
		++(*a_idx);
		++i;
	}
	free(strs);
}

void	push_args_to_a(t_stack *a, char **argv)
{
	int		i;
	int		a_idx;

	i = 1;
	a_idx = 0;
	while (argv[i])
	{
		if (ft_inset(' ', argv[i]))
		{
			push_str_with_space(argv[i], a, &a_idx);
			if (a->data == NULL)
				return ;
		}
		else
		{
			check_and_push(argv[i], a, a_idx);
			++a_idx;
		}
		++i;
	}
}
