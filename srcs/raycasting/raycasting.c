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

void	open_and_check(char *str)
{
	int	fd;

	fd = open(str, O_DIRECTORY);
	close(fd);
	if (fd > -1)
		exit_and_print(TEX_DIR);
	fd = open(str, O_RDONLY);
	if (fd < 0)
		exit_and_print(FAKE_XPM);
	else
		close(fd);	
}

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
		data->draw_end = HEIGHT + 1;
	double wall_x;
	if (!data->side)
		wall_x = data->pos_y + data->wall_dist * data->ray_dir_y;
	else
		wall_x = data->pos_x + data->wall_dist * data->ray_dir_x;
	wall_x -= floor(wall_x);
	int tex_x = (int)(wall_x * (double)TEX_SIZE);
	if (!data->side && data->ray_dir_x > 0)
		tex_x = TEX_SIZE - tex_x;
	if (data->side && data->ray_dir_y < 0)
		tex_x = TEX_SIZE - tex_x;
	double	step = 1.0 * TEX_SIZE / data->line_h;
	double	tex_pos = (data->draw_start - HEIGHT / 2 + data->line_h / 2) * step;
	int y = data->draw_start;
	char *color;
	while (++y <= data->draw_end)
	{
		int tex_y = (int)tex_pos & (TEX_SIZE - 1);
		tex_y += 1;
		tex_pos += step;
		if (data->side && data->step_y < 0 && data->hit)
		color = data->params->img_no.addr + (tex_y * data->params->img_no.line_length - tex_x * (data->params->img_no.bits_per_pixel / 8));
		else if (data->side && data->step_y > 0 && data->hit)
		color = data->params->img_so.addr + (tex_y * data->params->img_so.line_length - (tex_x+ 1) * (data->params->img_so.bits_per_pixel / 8));
		else if (!data->side && data->step_x > 0 && data->hit)
		color = data->params->img_ea.addr + (tex_y * data->params->img_ea.line_length - tex_x * (data->params->img_ea.bits_per_pixel / 8));
		else if (!data->side && data->step_x < 0 && data->hit)
		color = data->params->img_we.addr + (tex_y * data->params->img_we.line_length - (tex_x + 1) * (data->params->img_we.bits_per_pixel / 8));
		char *pxl = mlx->img.addr + (y * mlx->img.line_length + x * (mlx->img.bits_per_pixel / 8));
		*(int *)pxl = *(int *)color;
	}
}

void raycasting_loop(t_mlx *mlx, char **tab, t_p *params, t_d *data)
{
	int x;

	(void)params;
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

void	textures_init(t_p *params, t_mlx *mlx)
{
	params->img_no.img_data = mlx_xpm_file_to_image(mlx->ptr, params->no, &params->no_x, &params->no_y);
	params->img_no.addr = mlx_get_data_addr(params->img_no.img_data, &params->img_no.bits_per_pixel, &params->img_no.line_length, &params->img_no.endian);
	params->img_so.img_data = mlx_xpm_file_to_image(mlx->ptr, params->so, &params->so_x, &params->so_y);
	params->img_so.addr = mlx_get_data_addr(params->img_so.img_data, &params->img_so.bits_per_pixel, &params->img_so.line_length, &params->img_so.endian);
	params->img_we.img_data = mlx_xpm_file_to_image(mlx->ptr, params->we, &params->we_x, &params->we_y);
	params->img_we.addr = mlx_get_data_addr(params->img_we.img_data, &params->img_we.bits_per_pixel, &params->img_we.line_length, &params->img_we.endian);
	params->img_ea.img_data = mlx_xpm_file_to_image(mlx->ptr, params->ea, &params->ea_x, &params->ea_y);
	params->img_ea.addr = mlx_get_data_addr(params->img_ea.img_data, &params->img_ea.bits_per_pixel, &params->img_ea.line_length, &params->img_ea.endian);
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
	textures_init(&params, &mlx);
	mlx_mouse_hide();
	mlx_mouse_move(mlx.win, WIDTH / 2, HEIGHT / 2);
	raycasting_loop(&mlx, tab, &params, &data);
	mlx_hook(mlx.win, 2, 0, lock_key, &data);
	mlx_hook(mlx.win, 3, 0, unlock_key, &data);
	mlx_hook(mlx.win, 17, 0, destroy_win, (void *)0);
	mlx_hook(mlx.win, 4, 0, lock_mouse, (void *)0);
	mlx_loop_hook(mlx.ptr, key_action, &data);
	mlx_loop(mlx.ptr);
}
