/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:11:59 by jihyeole          #+#    #+#             */
/*   Updated: 2023/03/16 19:12:12 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}

int	filecheck(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	if (ft_strncmp(&filename[len - 4], ".ber", 4))
		return (0);
	return (1);
}

char	*strjoin_with_free(char *s1, char *s2)
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
	free(s1);
	free(s2);
	return (p);
}

char	*file_to_oneline(int fd, t_map *map)
{
	char	*file_oneline;
	char	*line;

	file_oneline = NULL;
	line = get_next_line(fd);
	map->width = strlen_without_nl(line);
	map->height = 0;
	while (line)
	{
		map->height++;
		file_oneline = strjoin_with_free(file_oneline, line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	return (file_oneline);
}
