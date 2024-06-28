/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 21:49:18 by jihyeole          #+#    #+#             */
/*   Updated: 2022/12/13 16:39:07 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}

int	have_newline(const char *buf)
{
	if (buf == 0)
		return (0);
	while (*buf)
	{
		if (*buf == '\n')
			return (1);
		buf++;
	}
	return (0);
}

void	ft_strncpy(char *dest, char *src, size_t n)
{
	while (n > 0)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
}

char	*ft_strjoin(char *temp, char *buf)
{
	size_t	temp_len;
	size_t	buf_len;
	char	*s;

	temp_len = ft_strlen(temp);
	buf_len = ft_strlen(buf);
	s = (char *)malloc(temp_len + buf_len + 1);
	if (!s)
	{
		if (temp)
			free(temp);
		return (NULL);
	}
	ft_strncpy(s, temp, temp_len);
	ft_strncpy(s + temp_len, buf, buf_len);
	s[temp_len + buf_len] = 0;
	if (temp)
		free(temp);
	return (s);
}
