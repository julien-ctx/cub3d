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

void print_rec(t_d *data, int width, int height, int color)
{
	int x;
	int y;

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

void print_pos(t_d *data)
{
	int x;
	int y;

	x = (WIDTH / MAP_COEF) / 2 - 4;
	while (++x < (WIDTH / MAP_COEF) / 2 + 3)
	{
		y = (WIDTH / MAP_COEF) / 2 - 4;
		while (++y < (WIDTH / MAP_COEF) / 2 + 3)
			ft_pixel_put(&data->mlx->map, x, y, BLUE);
	}
}

void retrieve_tab_size(t_d *data, t_map *map)
{
	int x;
	int y;

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

void print_walls(t_d *data)
{
	t_map map;
	int dist;

	retrieve_tab_size(data, &map);
	map.wall_size = (WIDTH / MAP_COEF - 6) / 5;
	map.x = 3;
	map.y = 3;
	dist = -2;
	double pos_x = data->pos_x;
	double pos_y = data->pos_y;
	while (map.x < WIDTH / MAP_COEF - 3 && dist < 3)
	{
		map.perc_x = pos_x + dist;
		map.curr_wall_x = floor(map.perc_x);
		map.perc_x -= floor(map.perc_x);
		map.perc_x *= map.wall_size;
		map.perc_y = pos_y + (double)dist;
		map.curr_wall_y = floor(map.perc_y);
		map.perc_y -= floor(map.perc_y);
		map.perc_y *= map.wall_size;
		map.pxl_x = 0;
		while (map.pxl_x < map.perc_x)
		{
			map.pxl_y = 0;
			while (map.pxl_y < map.perc_y)
			{
				if (map.curr_wall_x >= 0 && map.curr_wall_x <= map.tab_x
					&& map.curr_wall_y >= 0 && map.curr_wall_y <= map.tab_y)
				{
					if (data->tab[(int)map.curr_wall_y][(int)map.curr_wall_x] == '1')
						ft_pixel_put(&data->mlx->map, map.x + map.pxl_x, map.y + map.pxl_y, MAP_WALLS);
				}
				map.pxl_y++;
			}
			map.pxl_x++;
		}
		map.x += map.pxl_x;
		map.y += map.pxl_y;
		dist++;
	}
}

void print_map(t_d *data)
{
	print_rec(data, WIDTH / MAP_COEF, WIDTH / MAP_COEF, BORDER);
	print_rec(data, WIDTH / MAP_COEF - 3, WIDTH / MAP_COEF - 3, WHITE);
	print_walls(data);
	print_pos(data);
	mlx_put_image_to_window(data->mlx, data->mlx->win, data->mlx->map.img_data,
							WIDTH / WIDTH_COEF, HEIGHT / HEIGHT_COEF);
}
