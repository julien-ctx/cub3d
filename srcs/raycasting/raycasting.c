/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:43:29 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/13 22:18:26 by jcauchet         ###   ########.fr       */
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

void	draw_ver(int x, int y1, int y2, t_win *img)
{
		printf("%d, %d %d\n", y1, y2, x);
	if (y1 > HEIGHT || y2 > HEIGHT || y1 < 0 || y2 < 0)	
		return ;
	while (y1 < y2)
	{
		ft_pixel_put(img, x, y1, PXL);
		y1++;
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
		mlx->img.img_data = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
		mlx->img.addr = mlx_get_data_addr(mlx->img.img_data, &mlx->img.bits_per_pixel,
							&mlx->img.line_length, &mlx->img.endian);
		x = 0;
		while (x < WIDTH)
		{
			data.cam_x = 2 * x / (double)(WIDTH - 1);
			data.ray_x = data.dir_x + data.plane_x * data.cam_x;
			data.ray_y = data.dir_y + data.plane_y * data.cam_x;
			data.map_x = (int)data.pos_x;
			data.map_y = (int)data.pos_y;
			x++;
		}
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
