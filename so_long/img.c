/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:15:17 by jihyeole          #+#    #+#             */
/*   Updated: 2023/03/16 19:15:43 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_img(void *mlx, t_img *img)
{
	int		w;
	int		h;

	img->w = mlx_xpm_file_to_image(mlx, "./img/side.xpm", &w, &h);
	img->s = mlx_xpm_file_to_image(mlx, "./img/blue.xpm", &w, &h);
	img->c = mlx_xpm_file_to_image(mlx, "./img/rot.xpm", &w, &h);
	img->e = mlx_xpm_file_to_image(mlx, "./img/ambulance.xpm", &w, &h);
	img->p = mlx_xpm_file_to_image(mlx, "./img/zombie64.xpm", &w, &h);
}

void	put_img(void *mlx, void *win, char **map, t_img *img)
{
	int		row;
	int		col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col] && map[row][col] != '\n')
		{
			if (map[row][col] == '1')
				mlx_put_image_to_window(mlx, win, img->w, col * W, row * H);
			else
				mlx_put_image_to_window(mlx, win, img->s, col * W, row * H);
			if (map[row][col] == 'C')
				mlx_put_image_to_window(mlx, win, img->c, col * W, row * H);
			else if (map[row][col] == 'E')
				mlx_put_image_to_window(mlx, win, img->e, col * W, row * H);
			else if (map[row][col] == 'P')
				mlx_put_image_to_window(mlx, win, img->p, col * W, row * H);
			col++;
		}
		row++;
	}
}

void	move_img(t_vars *vars, int row_diff, int col_diff)
{
	int		row;
	int		col;
	int		x;
	int		y;

	row = vars->map->p_row;
	col = vars->map->p_col;
	x = col * W;
	y = row * H;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->s, x, y);
	if (vars->map->map[row][col] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->e, x, y);
	x = (col + col_diff) * W;
	y = (row + row_diff) * H;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->s, x, y);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->p, x, y);
	vars->map->p_row = row + row_diff;
	vars->map->p_col = col + col_diff;
	vars->cnt++;
	ft_printf("count: %d\n", vars->cnt);
}
