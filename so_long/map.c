/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:04:54 by jihyeole          #+#    #+#             */
/*   Updated: 2023/03/16 19:07:04 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check(t_map *map, int row, int col, int	*pe_cnt)
{
	if (!ft_inset(map->map[row][col], "10CPE"))
		return (0);
	if (row == 0 || row == map->height - 1 || col == 0 || col == map->width - 1)
	{
		if (map->map[row][col] != '1')
			return (0);
	}
	else if (map->map[row][col] == 'C')
		map->c_cnt++;
	else if (map->map[row][col] == 'E')
		pe_cnt[1]++;
	else if (map->map[row][col] == 'P')
	{
		pe_cnt[0]++;
		map->p_row = row;
		map->p_col = col;
	}
	return (1);
}

int	check_map(t_map *map)
{
	int		row;
	int		col;
	char	*line;
	int		pe_cnt[2];

	row = 0;
	pe_cnt[0] = 0;
	pe_cnt[1] = 0;
	while (row < map->height)
	{
		line = map->map[row];
		if ((int) strlen_without_nl(line) != map->width)
			return (0);
		col = 0;
		while (col < map->width)
		{
			if (!check(map, row, col, pe_cnt))
				return (0);
			col++;
		}
		row++;
	}
	if (map->c_cnt < 1 || pe_cnt[0] != 1 || pe_cnt[1] != 1)
		return (0);
	return (1);
}

void	map_route_check(char **map, int row, int col)
{
	map[row][col] = 'V';
	if (map[row - 1][col] != '1' && map[row - 1][col] != 'V')
		map_route_check(map, row - 1, col);
	if (map[row + 1][col] != '1' && map[row + 1][col] != 'V')
		map_route_check(map, row + 1, col);
	if (map[row][col - 1] != '1' && map[row][col - 1] != 'V')
		map_route_check(map, row, col - 1);
	if (map[row][col + 1] != '1' && map[row][col + 1] != 'V')
		map_route_check(map, row, col + 1);
}

int	is_map_valid(char *map_oneline, int p_row, int p_col)
{
	char	**map;
	int		row;
	int		col;

	map = ft_split(map_oneline, '\n');
	if (!map)
		ft_error("Error\n");
	map_route_check(map, p_row, p_col);
	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col] && map[row][col] != '\n')
		{
			if (map[row][col] == 'C' || map[row][col] == 'E')
			{
				free_map(map);
				return (0);
			}
			col++;
		}
		row++;
	}
	free_map(map);
	return (1);
}

void	get_map(t_map *map)
{
	map->map = ft_split(map->map_oneline, '\n');
	if (!map->map)
		ft_error("Error\n");
	if (!check_map(map))
	{
		free_t_map(map);
		ft_error("Error\nInvalid map\n");
	}
	if (!is_map_valid(map->map_oneline, map->p_row, map->p_col))
	{
		free_t_map(map);
		ft_error("Error\nInvalid map\n");
	}
}
