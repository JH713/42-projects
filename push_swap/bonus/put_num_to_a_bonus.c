/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_num_to_a_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 05:07:02 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/05 05:07:34 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	check_and_put(char *str, t_stack *a, int a_idx)
{
	if (!is_integer(str) || is_duplicate(a->data, a_idx, ft_atoi(str)))
	{
		free(a->data);
		a->data = NULL;
		return (0);
	}
		a->data[a_idx] = ft_atoi(str);
	return (1);
}

static void	put_str_with_space(char *str, t_stack *a, int *a_idx)
{
	int		i;
	char	**strs;

	strs = ft_split(str, ' ');
	if (*strs == NULL)
	{
		free(a->data);
		a->data = NULL;
		free(strs);
		return ;
	}
	i = 0;
	while (strs[i])
	{
		if (!check_and_put(strs[i], a, *a_idx))
			return ;
		++(*a_idx);
		++i;
	}
	free(strs);
}

void	put_num_to_a(t_stack *a, char **argv)
{
	int		i;
	int		a_idx;

	i = 1;
	a_idx = 0;
	while (argv[i])
	{
		if (ft_inset(' ', argv[i]))
		{
			put_str_with_space(argv[i], a, &a_idx);
			if (a->data == NULL)
				return ;
		}
		else
		{
			if (!check_and_put(argv[i], a, a_idx))
				return ;
			++a_idx;
		}
		++i;
	}
}
