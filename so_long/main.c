/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 21:11:54 by jihyeole          #+#    #+#             */
/*   Updated: 2023/03/16 19:15:27 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;
	int		fd;

	if (argc != 2)
		ft_error("Error\nInvalid number of arguments\n");
	if (!filecheck(argv[1]))
		ft_error("Error\nInvalid file name\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error("Error\nFailed to open file\n");
	map.map_oneline = file_to_oneline(fd, &map);
	if (!map.map_oneline)
		ft_error("Error\nFailed to get file content\n");
	close(fd);
	get_map(&map);
	window(&map);
}
