/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:06:29 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/05 23:40:56 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static size_t	word_cnt(const char *s, char c)
{
	size_t	cnt;

	if (s == 0)
		return (0);
	cnt = 0;
	while (*s != 0)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == 0))
			cnt++;
		s++;
	}
	return (cnt);
}

static int	get_arg_num(char **argv)
{
	int	i;
	int	cnt;

	i = 1;
	cnt = 0;
	while (argv[i])
	{
		if (argv[i][0] == 0)
			print_error();
		if (ft_inset(' ', argv[i]))
			cnt += word_cnt(argv[i], ' ');
		else
			++cnt;
		++i;
	}
	return (cnt);
}

void	init_a(t_stack *a, char **argv)
{
	int	arg_num;

	arg_num = get_arg_num(argv);
	a->data = (int *)malloc(sizeof(int) * (arg_num));
	if (a->data == NULL)
		print_error();
	a->head = 0;
	a->tail = arg_num - 1;
	a->size = arg_num;
	a->cnt = a->size;
	push_args_to_a(a, argv);
}

void	init_b(t_stack *b, int arg_num)
{
	b->data = (int *)malloc(sizeof(int) * (arg_num));
	if (b->data == NULL)
		print_error();
	b->head = -1;
	b->tail = -1;
	b->size = arg_num;
	b->cnt = 0;
}
