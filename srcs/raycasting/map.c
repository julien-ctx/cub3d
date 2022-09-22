/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:42:30 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/21 14:14:36by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	print_rec(t_d *data, int width, int height, int color)
{
	int	x;
	int	y;

	if (width == WIDTH / MAP_COEF)
		x = -1;
	else
		x = 2;
	while (++x < width)
	{
		if (height == WIDTH / MAP_COEF)
			y = -1;
		else
			y = 2;
		while (++y < height)
			ft_pixel_put(&data->mlx->map, x, y, color);
	}
}

void	print_pos(t_d *data)
{
	int	x;
	int	y;

	x = (WIDTH / MAP_COEF) / 2 - 4;
	while (++x < (WIDTH / MAP_COEF) / 2 + 3)
	{
		y = (WIDTH / MAP_COEF) / 2 - 4;
		while (++y < (WIDTH / MAP_COEF) / 2 + 3)
			ft_pixel_put(&data->mlx->map, x, y, BLUE);
	}
}

void	retrieve_tab_size(t_d *data, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (data->tab[y])
	{
		x = 0;
		while (data->tab[y][x])
			x++;
		y++;
	}
	map->tab_x = x;
	map->tab_y = y;
}

void	print_walls(t_d *data)
{
	t_map 	map;

	retrieve_tab_size(data, &map);
	map.wall_size = (WIDTH / MAP_COEF - 6) / 5;
	
	map.x = 3;
	while (++map.x < WIDTH / MAP_COEF - 3)
	{
		map.perc_x = data->pos_x - 2.0;
	map.curr_wall_x = floor(map.perc_x);
	map.perc_x -= floor(map.perc_x);
	map.perc_x = round(map.perc_x * map.wall_size);
	map.perc_y = data->pos_y - 2.0;
	map.curr_wall_y = floor(map.perc_y);
	map.perc_y -= floor(map.perc_y);
	map.perc_y = round(map.perc_y * map.wall_size);
		if (map.curr_wall_x >= 0 && map.curr_wall_x <= map.tab_x
			&& map.curr_wall_y >= 0 && map.curr_wall_y <= map.tab_y)
		{
			if (data->tab[(int)map.curr_wall_y][(int)map.curr_wall_x] == '1')
				map.wall = 1;
		}
		else
			map.wall = 0;
		map.pxl_x = 0;
		while (map.pxl_x < (int)map.perc_x && map.x < WIDTH / MAP_COEF - 3)
		{
			map.pxl_y = 0;
			while (map.pxl_y < (int)map.perc_y && map.y < WIDTH / MAP_COEF - 3)
			{
				if (map.wall)
					ft_pixel_put(&data->mlx->map, map.x, map.y, MAP_WALLS);
				map.pxl_y++;
			}
			map.y++;
			map.pxl_x++;
			map.x++;
		}
		if (map.x == WIDTH / MAP_COEF - 3)
			break ;
	}
}

void	print_map(t_d *data)
{
	print_rec(data, WIDTH / MAP_COEF, WIDTH / MAP_COEF, BORDER);
	print_rec(data, WIDTH / MAP_COEF - 3, WIDTH / MAP_COEF - 3, WHITE);
	print_walls(data);
	print_pos(data);
	mlx_put_image_to_window(data->mlx, data->mlx->win, data->mlx->map.img_data, 
			WIDTH / WIDTH_COEF, HEIGHT / HEIGHT_COEF);
}
