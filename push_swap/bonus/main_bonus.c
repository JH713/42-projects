/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 03:42:49 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/06 00:30:52 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	is_sorted(t_stack *a)
{
	int	i;
	int	j;

	i = a->head;
	while (i != a->tail)
	{
		j = get_stack_next_idx(a, i);
		if (a->data[j] < a->data[i])
			return (0);
		i = j;
	}
	return (1);
}

void	execute_rule(t_stack *a, t_stack *b, char *rule)
{
	if (ft_strncmp(rule, "sa", 3) == 0)
		rule_swap(a);
	else if (ft_strncmp(rule, "sb", 3) == 0)
		rule_swap(b);
	else if (ft_strncmp(rule, "ss", 3) == 0)
		rule_a_and_b(a, b, 0);
	else if (ft_strncmp(rule, "pa", 3) == 0)
		rule_push(b, a);
	else if (ft_strncmp(rule, "pb", 3) == 0)
		rule_push(a, b);
	else if (ft_strncmp(rule, "ra", 3) == 0)
		rule_rotate(a);
	else if (ft_strncmp(rule, "rb", 3) == 0)
		rule_rotate(b);
	else if (ft_strncmp(rule, "rr", 3) == 0)
		rule_a_and_b(a, b, 1);
	else if (ft_strncmp(rule, "rra", 4) == 0)
		rule_reverse_rotate(a);
	else if (ft_strncmp(rule, "rrb", 4) == 0)
		rule_reverse_rotate(b);
	else if (ft_strncmp(rule, "rrr", 4) == 0)
		rule_a_and_b(a, b, 2);
	else
		print_error();
}

void	read_and_execute(t_stack *a, t_stack *b)
{
	char	*line;
	char	*temp;
	char	**instructions;
	int		i;
	int		cnt_nl;

	line = NULL;
	temp = get_next_line(0);
	while (temp)
	{
		line = ft_strjoin(line, temp);
		instructions = ft_split(line, '\n');
		i = -1;
		cnt_nl = cnt_new_line(line);
		while (++i < cnt_nl)
			execute_rule(a, b, instructions[i]);
		free(line);
		line = ft_strdup(instructions[i]);
		free_instructions(instructions);
		temp = get_next_line(0);
	}
	if (line)
		print_error();
}

int	main(int argc, char **argv)
{
	int		arg_num;
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		return (0);
	arg_num = init_a(&a, argv);
	init_b(&b, arg_num);
	if (a.data == NULL || b.data == NULL)
		print_error();
	read_and_execute(&a, &b);
	if (is_sorted(&a) && b.cnt == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
