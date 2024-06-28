/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:22:11 by jihyeole          #+#    #+#             */
/*   Updated: 2023/03/16 19:28:07 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <stdio.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h"
# define W 64
# define H 64
# define KEY_PRESS 2
# define KEY_EXIT 17

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

typedef struct s_map
{
	char	**map;
	char	*map_oneline;
	int		width;
	int		height;
	int		p_row;
	int		p_col;
	int		c_cnt;
}	t_map;

typedef struct s_img
{
	void	*w;
	void	*s;
	void	*c;
	void	*e;
	void	*p;
}	t_img;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_img		*img;
	int			cnt;
}	t_vars;

int		main(int argc, char **argv);
int		check(t_map *map, int row, int col, int	*pe_cnt);
int		check_map(t_map *map);
void	map_route_check(char **map, int row, int col);
int		is_map_valid(char *map_oneline, int p_row, int p_col);
void	get_map(t_map *map);
void	free_map(char **map);
void	free_t_map(t_map *map);
int		ft_error(char *msg);
int		filecheck(char *filename);
char	*strjoin_with_free(char *s1, char *s2);
char	*file_to_oneline(int fd, t_map *map);
void	move(t_vars *vars, int row_diff, int col_diff);
int		key_hook(int keycode, t_vars *vars);
int		mouseclose(t_vars *vars);
void	window(t_map *map);
void	get_img(void *mlx, t_img *img);
void	put_img(void *mlx, void *win, char **map, t_img *img);
void	move_img(t_vars *vars, int row_diff, int col_diff);

#endif