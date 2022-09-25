/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:26:27 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/25 21:14:44 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	rgb_to_hex(int *rgb)
{
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

void	ft_pixel_put_map(t_img *img, t_point d, t_d *data)
{
	char	*pxl;

	if (((d.x < data->map->tab_x * data->map->wall_size)
			&& (d.x >= 0) && (d.y < data->map->tab_y * data->map->wall_size)
			&& (d.y >= 0)))
	{
		pxl = img->addr + (d.y * img->line_length
				+ d.x * (img->bits_per_pixel / 8));
		*(unsigned int *)pxl = (unsigned int)d.color;
	}
}

void	ft_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pxl;

	if (((x < WIDTH) && (x >= 0) && (y < HEIGHT) && (y >= 0)))
	{
		pxl = img->addr + (y * img->line_length
				+ x * (img->bits_per_pixel / 8));
		*(unsigned int *)pxl = (unsigned int) color;
	}
}

void	draw_ver(t_c c, t_img *img, int color)
{
	if (c.y1 > HEIGHT || c.y2 > HEIGHT || c.y1 < 0 || c.y2 < 0)
		return ;
	while (c.y1 <= c.y2)
	{
		ft_pixel_put(img, c.x, c.y1, color);
		c.y1++;
	}
}

void	init_background(t_mlx *mlx, t_p *params)
{
	int	i;

	i = -1;
	while (++i < WIDTH)
		draw_ver((t_c){i, 0, HEIGHT / 2}, &mlx->img, rgb_to_hex(params->c));
	i = -1;
	while (++i < WIDTH)
		draw_ver((t_c){i, HEIGHT / 2 + 1, HEIGHT},
			&mlx->img, rgb_to_hex(params->f));
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.img_data, 0, 0);
}
