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

void	retrieve_map(t_map *map, t_d *data)
{
	int	curr_x;
	int	curr_y;
	int	i;
	int	j;
	double	pos_y;

	map->map = malloc(sizeof(t_point *) * 5);
	i = -1;
	while (++i < 5)
		map->map[i] = malloc(sizeof(t_point) * 6);
	pos_y = data->pos_y;
	curr_x = (int)(data->pos_x - 2.5);
	i = 0;
	while (i < 5)
	{
		j = 0;
		curr_y = (int)(pos_y - 2.5);
		while (j < 5)
		{
			if (curr_x >= map->tab_x || curr_y >= map->tab_y
				|| curr_x < 0 || curr_y < 0)
				map->map[j][i].point = '0';
			else if (data->tab[curr_y][curr_x] == '1')
				map->map[j][i].point = '1';
			else
				map->map[j][i].point = '0';
			curr_y++;
			j++;
		}
		map->map[i][j].point = '\0';
		i++;
		curr_x++;
	}
}

void	retrieve_percents(t_map *map, t_d *data)
{
	map->wall_size = (WIDTH / MAP_COEF - 6) / 5;
	map->perc_x = data->pos_x - 2.5;
	map->perc_x -= floor(map->perc_x);
	if (!map->perc_x)
		map->perc_x = map->wall_size;
	else
		map->perc_x = map->wall_size - map->perc_x * map->wall_size;
	map->perc_y = data->pos_y - 2.5;
	map->perc_y -= floor(map->perc_y);
	if (!map->perc_y)
		map->perc_y = map->wall_size;
	else
		map->perc_y = map->wall_size - map->perc_y * map->wall_size;
}

void	print_percents(t_map *map, t_d *data)
{
	int i = 0;
	map->x = 3;
	int	index;
	while (map->x < map->wall_size)
	{
		if (map->map[0][i].point == '1')
		{
			index = 0;
			while (index < map->perc_x)
			{
				map->x += index;
				draw_ver((t_c){map->x, 3, 64}, &data->mlx->map, MAP_WALLS);
				index++;
			}
			map->x++;
		}
		else
			map->x += (int)map->perc_x;
		map->perc_x = map->wall_size;
		i++;
	}
}

void print_walls(t_d *data)
{
	t_map	map;

	retrieve_tab_size(data, &map);
	retrieve_map(&map, data);
	retrieve_percents(&map, data);	
	print_percents(&map, data);
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
