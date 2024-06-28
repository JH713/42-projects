/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:09:09 by jihyeole          #+#    #+#             */
/*   Updated: 2023/03/16 19:09:35 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	cnt;

	cnt = 0;
	while (map[cnt])
	{
		free(map[cnt]);
		cnt++;
	}
	free(map);
}

void	free_t_map(t_map *map)
{
	int	cnt;

	cnt = 0;
	if (map->map)
	{
		free_map(map->map);
		map->map = NULL;
	}
	if (map->map_oneline)
		free(map->map_oneline);
	map->map_oneline = NULL;
}
