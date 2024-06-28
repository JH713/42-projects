/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:13:57 by jihyeole          #+#    #+#             */
/*   Updated: 2023/03/16 19:15:01 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_vars *vars, int row_diff, int col_diff)
{
	char	block;
	int		row;
	int		col;

	row = vars->map->p_row;
	col = vars->map->p_col;
	block = vars->map->map[row + row_diff][col + col_diff];
	if (block != '1')
	{
		if (block == 'C')
		{
			vars->map->c_cnt--;
			vars->map->map[row + row_diff][col + col_diff] = '0';
			move_img(vars, row_diff, col_diff);
		}
		else if (block == 'E' && vars->map->c_cnt == 0)
		{
			vars->cnt++;
			ft_printf("count: %d\n", vars->cnt);
			free_t_map(vars->map);
			exit(0);
		}
		else
			move_img(vars, row_diff, col_diff);
	}
}

int	key_hook(int keycode, t_vars *vars)
{
	t_map	*map;
	int		row;
	int		col;

	map = vars->map;
	row = vars->map->p_row;
	col = vars->map->p_col;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free_t_map(vars->map);
		exit(0);
	}
	if (keycode == KEY_W)
		move(vars, -1, 0);
	else if (keycode == KEY_A)
		move(vars, 0, -1);
	else if (keycode == KEY_D)
		move(vars, 0, 1);
	else if (keycode == KEY_S)
		move(vars, 1, 0);
	return (0);
}

int	mouseclose(t_vars *vars)
{
	if (vars)
		mlx_destroy_window(vars->mlx, vars->win);
	free_t_map(vars->map);
	exit (0);
}

void	window(t_map *map)
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_vars		vars;

	mlx = mlx_init();
	win = mlx_new_window(mlx, map->width * W, map->height * H, "game");
	get_img(mlx, &img);
	put_img(mlx, win, map->map, &img);
	vars.mlx = mlx;
	vars.win = win;
	vars.map = map;
	vars.img = &img;
	vars.cnt = 0;
	mlx_key_hook(win, key_hook, &vars);
	mlx_hook(win, KEY_EXIT, 0, mouseclose, &vars);
	mlx_loop(mlx);
}
