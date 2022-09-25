/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:55:46 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/25 21:51:04 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

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

void	print_wall_line(t_tex *tex, t_d *data, t_mlx *mlx, int x)
{
	update_tex_data(tex, data, 1);
	while (++tex->y <= data->draw_end)
	{
		update_tex_data(tex, data, 0);
		if (data->side && data->step_y < 0 && data->hit)
				tex->color = data->params->img_no.addr
				+ (tex->tex_y * data->params->img_no.line_length - tex->tex_x
					* (data->params->img_no.bits_per_pixel / 8));
		else if (data->side && data->step_y > 0 && data->hit)
				tex->color = data->params->img_so.addr + (tex->tex_y
					* data->params->img_so.line_length - (tex->tex_x + 1)
					* (data->params->img_so.bits_per_pixel / 8));
		else if (!data->side && data->step_x > 0 && data->hit)
				tex->color = data->params->img_ea.addr
				+ (tex->tex_y * data->params->img_ea.line_length - tex->tex_x
					* (data->params->img_ea.bits_per_pixel / 8));
		else if (!data->side && data->step_x < 0 && data->hit)
				tex->color = data->params->img_we.addr + (tex->tex_y
					* data->params->img_we.line_length - (tex->tex_x + 1)
					* (data->params->img_we.bits_per_pixel / 8));
		tex->pxl = mlx->img.addr + (tex->y * mlx->img.line_length
				+ x * (mlx->img.bits_per_pixel / 8));
		*(int *)tex->pxl = *(int *)tex->color;
	}
}

void	raycasting_loop(t_mlx *mlx, char **tab, t_p *params, t_d *data)
{
	int	x;

	(void)params;
	init_background(mlx, params);
	x = -1;
	while (++x < WIDTH)
	{
		setup_ray(data, x, tab);
		print_tex(mlx, data, x);
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.img_data, 0, 0);
	if (data->minimap)
		print_map(data);
	mouse_rot(data);
}

void	minimap_init(t_d *data, t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (data->tab[y])
	{
		x = 0;
		while (data->tab[y][x])
			x++;
		y++;
	}
	data->map = malloc(sizeof(t_map));
	data->map->tab_x = x;
	data->map->tab_y = y;
	data->map->wall_size = (WIDTH / HEIGHT) * 6;
	mlx->map.img_data = mlx_new_image(mlx->ptr,
			data->map->tab_x * data->map->wall_size,
			data->map->tab_y * data->map->wall_size);
	mlx->map.addr = mlx_get_data_addr(mlx->map.img_data,
			&mlx->map.bits_per_pixel,
			&mlx->map.line_length, &mlx->map.endian);
}

void	raycasting(char **tab, t_p params)
{
	t_mlx	mlx;
	t_d		data;

	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, WIDTH, HEIGHT, "CUB3D");
	init_data(tab, &data, &mlx, &params);
	mlx.img.img_data = mlx_new_image(mlx.ptr, WIDTH, HEIGHT);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img_data,
			&mlx.img.bits_per_pixel,
			&mlx.img.line_length, &mlx.img.endian);
	textures_init(&params, &mlx);
	minimap_init(&data, &mlx);
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
