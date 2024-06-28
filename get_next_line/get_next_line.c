/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 21:49:15 by jihyeole          #+#    #+#             */
/*   Updated: 2022/12/29 16:35:20 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_remain(char *s, char **line, size_t idx)
{
	size_t	len;
	char	*remain;

	len = ft_strlen(s) - idx;
	remain = (char *)malloc(len + 1);
	if (!remain)
	{
		free(*line);
		free(s);
		return (NULL);
	}
	ft_strncpy(remain, s + idx, len);
	remain[len] = 0;
	free(s);
	return (remain);
}

static char	*split_with_newline(char *s, char **line)
{
	size_t	idx;

	idx = 0;
	while (s[idx] != '\n')
		idx++;
	idx++;
	*line = (char *)malloc(idx + 1);
	if (!(*line))
	{
		free(s);
		return (NULL);
	}
	ft_strncpy(*line, s, idx);
	(*line)[idx] = 0;
	if (s[idx] == 0)
	{
		free(s);
		return ("");
	}
	return (get_remain(s, line, idx));
}

static char	*read_under_zero(ssize_t read_size, char **line, char **temp)
{
	if (read_size < 0)
	{
		if (*temp)
		{
			free(*temp);
			*temp = 0;
		}
		return (NULL);
	}
	if (read_size == 0)
	{
		if (!(*temp))
			return (NULL);
		*line = *temp;
		*temp = 0;
		return (*line);
	}
	return (NULL);
}

static char	*line_with_nl(char **temp, char **line)
{
	*temp = split_with_newline(*temp, line);
	if (!(*temp))
		return (NULL);
	if ((*temp)[0] == 0)
		*temp = 0;
	return (*line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		buf[BUFFER_SIZE + 1];
	static char	*temp;
	ssize_t		read_size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (have_newline(temp))
			return (line_with_nl(&temp, &line));
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size <= 0)
			return (read_under_zero(read_size, &line, &temp));
		buf[read_size] = 0;
		temp = ft_strjoin(temp, buf);
		if (!temp)
			return (NULL);
		if (!have_newline(temp) && read_size < BUFFER_SIZE)
		{
			line = temp;
			temp = 0;
			return (line);
		}
	}
}
