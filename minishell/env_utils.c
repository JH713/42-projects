/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:56:40 by jihyeole          #+#    #+#             */
/*   Updated: 2023/05/15 20:57:18 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_value(t_env *env_lst, char *key)
{
	while (env_lst)
	{
		if (ft_strncmp(env_lst->key, key, ft_strlen(key) + 1) == 0)
			return (env_lst->value);
		env_lst = env_lst->next;
	}
	return (NULL);
}

void	join_env(char **line, char *env_value, int start, int end)
{
	char	*temp;
	char	*head;
	char	*tail;

	temp = *line;
	if (start == 0)
		head = NULL;
	else
		head = ft_substr(temp, 0, start);
	if (end == (int)ft_strlen(temp))
		tail = NULL;
	else
		tail = ft_substr(temp, end, ft_strlen(temp) - end);
	free(temp);
	temp = ft_strjoin(head, env_value);
	*line = ft_strjoin(temp, tail);
	free(temp);
}

void	expand_env(char **line, t_env *env_lst)
{
	int		i;
	int		j;
	char	*env_key;
	char	*env_value;

	i = 0;
	while (*line && (*line)[i])
	{
		if ((*line)[i] == '$')
		{
			j = 1;
			while (ft_inset((*line)[i + j], " \0$") == 0)
				j++;
			if (j == 1)
				continue ;
			env_key = ft_substr(&(*line)[i + 1], 0, j - 1);
			env_value = get_env_value(env_lst, env_key);
			join_env(line, env_value, i, i + j);
			i += ft_strlen(env_value);
		}
		else
			++i;
	}
}