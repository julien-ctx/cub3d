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
		if (height == HEIGHT / MAP_COEF)
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
		y = (HEIGHT / MAP_COEF) / 2 - 4;
		while (++y < (HEIGHT / MAP_COEF) / 2 + 3)
			ft_pixel_put(&data->mlx->map, x, y, BLUE);
	}
}

void	print_map(t_d *data)
{
	print_rec(data, WIDTH / MAP_COEF, HEIGHT / MAP_COEF, BORDER);
	print_rec(data, WIDTH / MAP_COEF - 3, HEIGHT / MAP_COEF - 3, WHITE);
	print_pos(data);
	mlx_put_image_to_window(data->mlx, data->mlx->win, data->mlx->map.img_data, 
			WIDTH / WIDTH_COEF, HEIGHT / HEIGHT_COEF);
}
