/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:54:32 by juliencauch       #+#    #+#             */
/*   Updated: 2022/09/17 12:36:06 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	dda(t_d *data, char **tab)
{
	while (!data->hit)
	{
		if (data->s_dist_x < data->s_dist_y)
		{
			data->s_dist_x += data->delta_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->s_dist_y += data->delta_y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		if (tab[data->map_y][data->map_x] == '1')
			data->hit = 1;
	}
}

void	stepping(t_d *data)
{
	if (data->ray_dir_x < 0)
	{
		data->step_x = -1;
		data->s_dist_x = (data->pos_x - data->map_x) * data->delta_x;
	}
	else
	{
		data->step_x = 1;
		data->s_dist_x = (data->map_x + 1.0 - data->pos_x) * data->delta_x;
	}
	if (data->ray_dir_y < 0)
	{
		data->step_y = -1;
		data->s_dist_y = (data->pos_y - data->map_y) * data->delta_y;
	}
	else
	{
		data->step_y = 1;
		data->s_dist_y = (data->map_y + 1.0 - data->pos_y) * data->delta_y;
	}
}

void	setup_ray(t_d *data, int x, char **tab)
{
	data->cam_x = 2 * x / (double)(WIDTH)-1;
	data->ray_dir_x = data->dir_x + data->plane_x * data->cam_x;
	data->ray_dir_y = data->dir_y + data->plane_y * data->cam_x;
	data->map_x = (int)data->pos_x;
	data->map_y = (int)data->pos_y;
	if (!data->ray_dir_x)
		data->delta_x = INFINITY;
	else
		data->delta_x = fabs(1 / data->ray_dir_x);
	if (!data->ray_dir_y)
		data->delta_y = INFINITY;
	else
		data->delta_y = fabs(1 / data->ray_dir_y);
	data->hit = 0;
	stepping(data);
	dda(data, tab);
}
