/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:43:29 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/14 19:12:03 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	print_values(t_d *data)
{
	printf("-------------------------\n");
	printf("%f pos_x\n", data->pos_x);
	printf("%f pos_y\n", data->pos_y);
	printf("%f dir_x\n", data->dir_x);
	printf("%f dir_y\n", data->dir_y);
	printf("%f plane_x\n", data->plane_x);
	printf("%f plane_y\n", data->plane_y);
	printf("%f time\n", data->time);
	printf("%f old_time\n", data->old_time);
	printf("%f cam_x\n", data->cam_x);
	printf("%f ray_dir_x\n", data->ray_dir_x);
	printf("%f ray_dir_y\n", data->ray_dir_y);
	printf("%f s_dist_x\n", data->s_dist_x);
	printf("%f s_dist_y\n", data->s_dist_y);
	printf("%f delta_x\n", data->delta_x);
	printf("%f delta_y\n", data->delta_y);
	printf("%f wall_dist\n", data->wall_dist);
	printf("%d map_x\n", data->map_x);
	printf("%d map_y\n", data->map_y);
	printf("%d step_x\n", data->step_x);
	printf("%d step_y\n", data->step_y);
	printf("%d hit\n", data->hit);
	printf("%d side\n", data->side);
	printf("%d line_h\n", data->line_h);
	printf("%d draw_start\n", data->draw_start);
	printf("%d draw_end\n", data->draw_end);
	printf("-------------------------\n");
}

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
		// printf("%d, %d %d\n", y1, y2, x);
	if (y1 > HEIGHT || y2 > HEIGHT || y1 < 0 || y2 < 0)	
		return ;
	while (y1 <= y2)
	{
		ft_pixel_put(img, x, y1, PXL);
		y1++;
	}
}

void	draw_ver_c(int x, int y1, int y2, t_win *img)
{
		// printf("%d, %d %d\n", y1, y2, x);
	if (y1 > HEIGHT || y2 > HEIGHT || y1 < 0 || y2 < 0)	
		return ;
	while (y1 <= y2)
	{
		ft_pixel_put(img, x, y1, CEILING);
		y1++;
	}
}
void	draw_ver_f(int x, int y1, int y2, t_win *img)
{
		// printf("%d, %d %d\n", y1, y2, x);
	if (y1 > HEIGHT || y2 > HEIGHT || y1 < 0 || y2 < 0)	
		return ;
	while (y1 <= y2)
	{
		ft_pixel_put(img, x, y1, FLOOR);
		y1++;
	}
}

void	init_background(t_mlx *mlx)	
{
	int	i;

		mlx->img.img_data = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
		mlx->img.addr = mlx_get_data_addr(mlx->img.img_data, &mlx->img.bits_per_pixel,
							&mlx->img.line_length, &mlx->img.endian);
	i = 0;
	while (i < WIDTH)
	{
		draw_ver_c(i, 0, HEIGHT / 2, &mlx->img);
		i++;
	}
	i = 0;
	while (i < WIDTH)
	{
		draw_ver_f(i, HEIGHT / 2 + 1, HEIGHT, &mlx->img);
		i++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.img_data, 0, 0);
}

void	raycasting_loop(t_mlx *mlx, char **tab, t_p params)
{
	t_d	data;
	int	x;
		
	(void)mlx;
	(void)params;
	init_data(tab, &data);
	init_background(mlx);
	while (1)
	{
		x = 0;
		while (x < WIDTH)
		{
			data.cam_x = 2 * x / (double)(WIDTH) - 1;
			data.ray_dir_x = data.dir_x + data.plane_x * data.cam_x;
			data.ray_dir_y = data.dir_y + data.plane_y * data.cam_x;
			data.map_x = (int)data.pos_x;
			data.map_y = (int)data.pos_y;
			if (!data.ray_dir_x)
				data.delta_x = INFINITY;
			else
				data.delta_x = fabs(1 / data.ray_dir_x);
			if (!data.ray_dir_y)
				data.delta_y = INFINITY;
			else
				data.delta_y = fabs(1 / data.ray_dir_y);
			data.hit = 0;
			if (data.ray_dir_x < 0)
			{
				data.step_x = -1;
				data.s_dist_x = (data.pos_x - data.map_x) * data.delta_x;
			}
			else
			{
				data.step_x = 1;
				data.s_dist_x = (data.map_x + 1.0 - data.pos_x) * data.delta_x;
			}
			if (data.ray_dir_y < 0)
			{
				data.step_y = -1;
				data.s_dist_y = (data.pos_y - data.map_y) * data.delta_y;
			}
			else
			{
				data.step_y = 1;
				data.s_dist_y = (data.map_y + 1.0 - data.pos_y) * data.delta_y;
			}
			while (!data.hit)
			{
				if (data.s_dist_x < data.s_dist_y)
				{
					data.s_dist_x += data.delta_x;
					data.map_x += data.step_x;
					data.side = 0;
				}
				else
				{
					data.s_dist_y += data.delta_y;
					data.map_y += data.step_y;
					data.side = 1;
				}
				if (tab[data.map_y][data.map_x] == '1')
					data.hit = 1;
			}
			if (!data.side)
				data.wall_dist = data.s_dist_x - data.delta_x;
			else
				data.wall_dist = data.s_dist_y - data.delta_y;
			data.line_h = (int)(HEIGHT / data.wall_dist);
			data.draw_start = -data.line_h / 2 + HEIGHT / 2;
			if (data.draw_start < 0)
				data.draw_start = 0;
			data.draw_end = data.line_h / 2 + HEIGHT / 2;
			if (data.draw_end >= HEIGHT)
				data.draw_end = HEIGHT - 1;
			draw_ver(x, data.draw_start, data.draw_end, &mlx->img);
			x++;
		}
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.img_data, 0, 0);
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
