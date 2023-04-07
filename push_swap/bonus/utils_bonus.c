/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 05:05:04 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/05 23:47:57 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	free_instructions(char **instructions)
{
	int	i;

	i = 0;
	while (instructions[i])
	{
		free(instructions[i]);
		++i;
	}
	free(instructions);
}

char	*ft_strjoin_with_free(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*p;

	if (s1 == NULL)
		return ((char *)s2);
	if (s2 == NULL)
		return ((char *)s1);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	p = (char *)malloc(s1_len + s2_len + 1);
	if (p == NULL)
		return (NULL);
	ft_strlcpy(p, s1, s1_len + 1);
	ft_strlcat(p, s2, s1_len + s2_len + 1);
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (p);
}

int	cnt_new_line(const char *line)
{
	int	cnt;

	cnt = 0;
	while (*line)
	{
		if (*line == '\n')
			++cnt;
		++line;
	}
	return (cnt);
}

int	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	get_stack_next_idx(t_stack *stack, int curr)
{
	int	next;

	if (curr == stack->tail)
		next = stack->head;
	else if (curr == stack->size - 1)
		next = 0;
	else
		next = curr + 1;
	return (next);
}
