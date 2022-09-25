/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 21:46:45 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/25 21:47:49 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	update_tex_data(t_tex *tex, t_d *data, int b)
{
	if (b)
	{
		tex->step = 1.0 * TEX_SIZE / data->line_h;
		tex->tex_pos = (data->draw_start - HEIGHT
				/ 2.0 + data->line_h / 2.0) * tex->step;
		tex->y = data->draw_start ;
		return ;
	}
	tex->tex_y = (int)tex->tex_pos & (TEX_SIZE - 1);
	tex->tex_y += 1;
	tex->tex_pos += tex->step;
}

void	print_tex(t_mlx *mlx, t_d *data, int x)
{
	t_tex	tex;

	if (!data->side)
		data->wall_dist = data->s_dist_x - data->delta_x;
	else
		data->wall_dist = data->s_dist_y - data->delta_y;
	data->line_h = (int)(HEIGHT / data->wall_dist);
	data->draw_start = -1 * data->line_h / 2.0 + HEIGHT / 2.0 + 1;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->line_h / 2.0 + HEIGHT / 2.0;
	if (data->draw_end >= HEIGHT)
		data->draw_end = HEIGHT + 1;
	if (!data->side)
		tex.wall_x = data->pos_y + data->wall_dist * data->ray_dir_y;
	else
		tex.wall_x = data->pos_x + data->wall_dist * data->ray_dir_x;
	tex.wall_x -= floor(tex.wall_x);
	tex.tex_x = (int)(tex.wall_x * (double)TEX_SIZE);
	if (!data->side && data->ray_dir_x > 0)
		tex.tex_x = TEX_SIZE - tex.tex_x;
	if (data->side && data->ray_dir_y < 0)
		tex.tex_x = TEX_SIZE - tex.tex_x;
	print_wall_line(&tex, data, mlx, x);
}

void	textures_init(t_p *params, t_mlx *mlx)
{
	params->img_no.img_data = mlx_xpm_file_to_image(mlx->ptr,
			params->no, &params->no_x, &params->no_y);
	params->img_no.addr = mlx_get_data_addr(params->img_no.img_data,
			&params->img_no.bits_per_pixel, &params->img_no.line_length,
			&params->img_no.endian);
	params->img_so.img_data = mlx_xpm_file_to_image(mlx->ptr,
			params->so, &params->so_x, &params->so_y);
	params->img_so.addr = mlx_get_data_addr(params->img_so.img_data,
			&params->img_so.bits_per_pixel, &params->img_so.line_length,
			&params->img_so.endian);
	params->img_we.img_data = mlx_xpm_file_to_image(mlx->ptr,
			params->we, &params->we_x, &params->we_y);
	params->img_we.addr = mlx_get_data_addr(params->img_we.img_data,
			&params->img_we.bits_per_pixel, &params->img_we.line_length,
			&params->img_we.endian);
	params->img_ea.img_data = mlx_xpm_file_to_image(mlx->ptr,
			params->ea, &params->ea_x, &params->ea_y);
	params->img_ea.addr = mlx_get_data_addr(params->img_ea.img_data,
			&params->img_ea.bits_per_pixel, &params->img_ea.line_length,
			&params->img_ea.endian);
}
