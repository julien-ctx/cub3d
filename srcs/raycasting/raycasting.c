/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:43:29 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/13 14:54:12 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key(int key, void *param)
{
	(void)param;
	if (key == 53)
		exit(0);
	return (0);
}

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

void	raycasting_loop(t_mlx *mlx, char **tab, t_p params)
{
	t_d	data;
	int	x;
		
	(void)mlx;
	(void)params;
	init_data(tab, &data);
	while (1)
	{
		x = -1;
		while (++x < WIDTH)
		{
			data.cam_x = 2 * x / (double)WIDTH - 1;
			data.ray_x = data.dir_x + data.plane_x * data.cam_x;
			data.map_x = (int)data.pos_x;
			data.map_y = (int)data.pos_y;
			if (!data.ray_x)
				data.delta_x = 0;
			else
				data.delta_x = (double)fabs(1 / data.dir_x);
			if (!data.ray_y)
				data.delta_y = 0;
			else
				data.delta_y = (double)fabs(1 / data.dir_y);
		}
		// mlx->img.img_data = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
		// mlx->img.addr = mlx_get_data_addr(mlx->img.img_data, &mlx->img.bits_per_pixel,
					// &mlx->img.line_length, &mlx->img.endian);

		// mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.img_data, 0, 0);
	// ft_pixel_put(&mlx->img, 1900, 80, 0x0055FFFF);
	// mlx_destroy_image(mlx->ptr, mlx->img.img_data);
	// mlx_clear_window(mlx->ptr, mlx->win);
	mlx_loop(mlx->ptr);
	}
}

void	raycasting(char **tab, t_p params)
{
	t_mlx	mlx;
	
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, WIDTH, HEIGHT, "CUB3D");
	mlx_key_hook(mlx.win, key, (void *)0);
	raycasting_loop(&mlx, tab, params);
}
