/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:50:26 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/25 22:12:58 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	handle_up_down(t_d *data, int dir)
{
	if (dir == UP)
	{
		if (data->tab[(int)data->pos_y]
			[(int)(data->pos_x + data->dir_x * data->move_speed)] != '1')
			data->pos_x += data->dir_x * data->move_speed;
		if (data->tab[(int)(data->pos_y + data->dir_y * data->move_speed)]
			[(int)data->pos_x] != '1')
			data->pos_y += data->dir_y * data->move_speed;
	}
	else
	{
		if (data->tab[(int)data->pos_y]
			[(int)(data->pos_x - data->dir_x * data->move_speed)] != '1')
			data->pos_x -= data->dir_x * data->move_speed;
		if (data->tab[(int)(data->pos_y - data->dir_y * data->move_speed)]
			[(int)data->pos_x] != '1')
			data->pos_y -= data->dir_y * data->move_speed;
	}
}

void	handle_dir(t_d *data, int dir)
{
	if (dir == LEFT)
	{
		if (data->tab[(int)data->pos_y]
			[(int)(data->pos_x - data->plane_x * data->move_speed)] != '1')
			data->pos_x -= data->plane_x * data->move_speed;
		if (data->tab[(int)(data->pos_y - data->plane_y * data->move_speed)]
			[(int)data->pos_x] != '1')
			data->pos_y -= data->plane_y * data->move_speed;
	}
	else
	{
		if (data->tab[(int)data->pos_y]
			[(int)(data->pos_x + data->plane_x * data->move_speed)] != '1')
			data->pos_x += data->plane_x * data->move_speed;
		if (data->tab[(int)(data->pos_y + data->plane_y * data->move_speed)]
			[(int)data->pos_x] != '1')
			data->pos_y += data->plane_y * data->move_speed;
	}
}

void	handle_rot(t_d *data, int dir, double speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	old_plane_x = data->plane_x;
	if (dir == R_LEFT)
	{
		data->dir_x = data->dir_x * cos(-1 * speed)
			- data->dir_y * sin(-1 * speed);
		data->dir_y = old_dir_x * sin(-1 * speed)
			+ data->dir_y * cos(-1 * speed);
		data->plane_x = data->plane_x * cos(-1 * speed)
			- data->plane_y * sin(-1 * speed);
		data->plane_y = old_plane_x * sin(-1 * speed)
			+ data->plane_y * cos(-1 * speed);
		return ;
	}
	data->dir_x = data->dir_x * cos(speed)
		- data->dir_y * sin(speed);
	data->dir_y = old_dir_x * sin(speed)
		+ data->dir_y * cos(speed);
	data->plane_x = data->plane_x * cos(speed)
		- data->plane_y * sin(speed);
	data->plane_y = old_plane_x * sin(speed)
		+ data->plane_y * cos(speed);
}
