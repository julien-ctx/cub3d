/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:43:29 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/16 14:49:41jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void print_values(t_d *data)
{
	printf("-------------------------\n");
	printf("%f pos_x\n", data->pos_x);
	printf("%f pos_y\n", data->pos_y);
	printf("%f dir_x\n", data->dir_x);
	printf("%f dir_y\n", data->dir_y);
	printf("%f plane_x\n", data->plane_x);
	printf("%f plane_y\n", data->plane_y);
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

void print_wall_line(t_mlx *mlx, t_d *data, int x)
{
	if (!data->side)
		data->wall_dist = data->s_dist_x - data->delta_x;
	else
		data->wall_dist = data->s_dist_y - data->delta_y;
	data->line_h = (int)(HEIGHT / data->wall_dist);
	data->draw_start = -1 * data->line_h / 2 + HEIGHT / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->line_h / 2 + HEIGHT / 2;
	if (data->draw_end >= HEIGHT)
		data->draw_end = HEIGHT - 1;
	draw_ver((t_c){x, data->draw_start, data->draw_end}, &mlx->img, PXL);
}

void raycasting_loop(t_mlx *mlx, char **tab, t_p *params, t_d *data)
{
	int x;

	(void)params;
	mlx_mouse_hide();
	init_background(mlx, params);
	x = -1;
	while (++x < WIDTH)
	{
		setup_ray(data, x, tab);
		print_wall_line(mlx, data, x);
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.img_data, 0, 0);
	mouse_rot(data);
}

void raycasting(char **tab, t_p params)
{
	t_mlx mlx;
	t_d data;

	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, WIDTH, HEIGHT, "CUB3D");
	init_data(tab, &data, &mlx, &params);
	mlx.img.img_data = mlx_new_image(mlx.ptr, WIDTH, HEIGHT);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img_data,
			&mlx.img.bits_per_pixel,
			&mlx.img.line_length, &mlx.img.endian);
	mlx_mouse_hide();
	raycasting_loop(&mlx, tab, &params, &data);
	mlx_hook(mlx.win, 2, 0, lock_key, &data);
	mlx_hook(mlx.win, 3, 0, unlock_key, &data);
	mlx_loop_hook(mlx.ptr, key_action, &data);
	mlx_loop(mlx.ptr);
}
