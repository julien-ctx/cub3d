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

void	draw_square(int x, int color, t_d *data)
{
	int	i;

	i = -1;
	while (++i < data->map->wall_size)
		draw_ver((t_c){x + i, data->map->y, data->map->y + data->map->wall_size}, &data->mlx->map, color);
}

void	print_tiles(t_d *data)
{
	int	x;
	int	y;

	y = -1;
	data->map->y = 0;
	while (data->tab[++y])
	{
		x = -1;
		data->map->x = 0;
		while (data->tab[y][++x])
		{
			if (data->tab[y][x] == '1')
				draw_square(data->map->x, BLUE, data);
			else
				draw_square(data->map->x, MAP_SPACES, data);
			data->map->x += data->map->wall_size;
		}
		data->map->y += data->map->wall_size;
	}
}

void print_map(t_d *data)
{
	print_tiles(data);
	// print_pos(data);
	mlx_put_image_to_window(data->mlx, data->mlx->win, data->mlx->map.img_data,
							WIDTH / WIDTH_COEF, HEIGHT / HEIGHT_COEF);
}
