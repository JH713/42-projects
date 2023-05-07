/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 07:35:08 by jihyeole          #+#    #+#             */
/*   Updated: 2023/05/07 20:15:54 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	my_exp(int base, int n)
{
	int	i;
	int	result;

	i = 0;
	if (n == 0)
		return (1);
	result = 1;
	while (i < n)
	{
		result *= base;
		++i;
	}
	return (result);
}

#include <stdio.h>

int	main(int argc, char *argv[])
{
	int		pid;
	char	*str;
	int		i;
	int		zero_cnt;
	int		bit;
	int		j;

	if (argc != 3)
	{
		ft_putendl_fd("Error: two arguments required", 2);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	str = argv[2];
	j = 0;
	zero_cnt = 0;
	while (zero_cnt != 8)
	{
		i = 7;
		zero_cnt = 0;
		while (i >= 0)
		{
			if (str[j] >= my_exp(2, i))
			{
				bit = 1;
				str[j] -= my_exp(2, i);
			}
			else
			{
				bit = 0;
				++zero_cnt;
			}
			printf("%d", bit);
			--i;
		}
		printf("\n");
		++j;
	}
}
