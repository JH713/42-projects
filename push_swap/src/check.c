/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:09:17 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/05 23:40:54 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_num(char *num)
{
	while (*num)
	{
		if (!ft_isdigit(*num))
			return (0);
		num++;
	}
	return (1);
}

int	is_integer(char *num)
{
	if (*num == '-')
	{
		if (*(num + 1) == 0 || ft_strlen(num) > 11 || !check_num(num + 1))
			return (0);
		if (ft_strlen(num) == 11)
		{
			if (*(num + 1) != '1' && *(num + 1) != '2')
				return (0);
			if (ft_atoi(num) > 0)
				return (0);
		}
	}
	else
	{
		if (ft_strlen(num) > 10 || !check_num(num))
			return (0);
		if (ft_strlen(num) == 10)
		{
			if (*num != '1' && *num != '2')
				return (0);
			if (ft_atoi(num) < 0)
				return (0);
		}
	}
	return (1);
}

int	is_duplicate(int *a, int i, int num)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (a[j] == num)
			return (1);
		j++;
	}
	return (0);
}
