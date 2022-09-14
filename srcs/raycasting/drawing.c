/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:22:09 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/14 23:09:29 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_pixel_put(t_win *img, int x, int y, int color)
{
	char	*pxl;

	if (((x < WIDTH) && (x >= 0) && (y < HEIGHT) && (y >= 0)))
	{
		pxl = img->addr + (y * img->line_length
				+ x * (img->bits_per_pixel / 8));
		*(unsigned int *)pxl = color;
	}
}

void	draw_ver(t_c c, t_win *img, int color)
{
	if (c.y1 > HEIGHT || c.y2 > HEIGHT || c.y1 < 0 || c.y2 < 0)
		return ;
	while (c.y1 <= c.y2)
	{
		ft_pixel_put(img, c.x, c.y1, color);
		c.y1++;
	}
}

void	init_background(t_mlx *mlx)
{
	int	i;

	mlx->img.img_data = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img_data,
			&mlx->img.bits_per_pixel,
			&mlx->img.line_length, &mlx->img.endian);
	i = -1;
	while (++i < WIDTH)
		draw_ver((t_c){i, 0, HEIGHT / 2}, &mlx->img, CEILING);
	i = -1;
	while (++i < WIDTH)
		draw_ver((t_c){i, HEIGHT / 2 + 1, HEIGHT}, &mlx->img, FLOOR);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.img_data, 0, 0);
}
