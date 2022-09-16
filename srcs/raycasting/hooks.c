/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:04:59 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/16 16:52:13 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	handle_up(t_d *data)
{
	if (data->tab[(int)data->pos_y][(int)(data->pos_x + data->dir_x * data->move_speed)] != '1')
		data->pos_x += data->dir_x * data->move_speed;
	if (data->tab[(int)(data->pos_y + data->dir_y * data->move_speed)][(int)data->pos_x] != '1')
		data->pos_y += data->dir_y * data->move_speed;
	// mlx_clear_window(data->mlx->ptr, data->mlx->win);
}

void	handle_down(t_d *data)
{
	if (data->tab[(int)data->pos_y][(int)(data->pos_x - data->dir_x * data->move_speed)] != '1')
		data->pos_x -= data->dir_x * data->move_speed;
	if (data->tab[(int)(data->pos_y - data->dir_y * data->move_speed)][(int)data->pos_x] != '1')
		data->pos_y -= data->dir_y * data->move_speed;
	// mlx_clear_window(data->mlx->ptr, data->mlx->win);
}

void	handle_rot(t_d *data, int dir)
{
	double	old_dir_x;
	double	old_plane_x;
	
	if (dir == LEFT)
	{
		old_dir_x = data->dir_x;
		data->dir_x = data->dir_x * cos(-1 * ROT_SPEED) - data->dir_y * sin(-1 * ROT_SPEED);
		data->dir_y = old_dir_x * sin(-1 * ROT_SPEED) + data->dir_y * cos(-1 * ROT_SPEED);
		old_plane_x = data->plane_x;
		data->plane_x = data->plane_x * cos(-1 * ROT_SPEED) - data->plane_y * sin(-1 * ROT_SPEED);
		data->plane_y = old_plane_x * sin(-1 * ROT_SPEED) + data->plane_y * cos(-1 * ROT_SPEED);
	}
	else
	{
		old_dir_x = data->dir_x;
		data->dir_x = data->dir_x * cos(ROT_SPEED) - data->dir_y * sin(ROT_SPEED);
		data->dir_y = old_dir_x * sin(ROT_SPEED) + data->dir_y * cos(ROT_SPEED);
		old_plane_x = data->plane_x;
		data->plane_x = data->plane_x * cos(ROT_SPEED) - data->plane_y * sin(ROT_SPEED);
		data->plane_y = old_plane_x * sin(ROT_SPEED) + data->plane_y * cos(ROT_SPEED);	
	}
}

int	key_action(t_d *data)
{
	if (data->w)
		handle_up(data);
	else if (data->s)
		handle_down(data);
	if (data->r)
		handle_rot(data, RIGHT);
	else if (data->l)
		handle_rot(data, LEFT);
	raycasting_loop(data->mlx, data->tab, data->params, data);	
	return (0);
}

int	unlock_key(int key, t_d *data)
{
	if (key == UP)
		data->w = 0;
	else if (key == DOWN)
		data->s = 0;
	else if (key == RIGHT)
		data->d = 0;
	else if (key == LEFT)
		data->a = 0;
	else if (key == R_RIGHT)
		data->r = 0;
	else if (key == R_LEFT)
		data->l = 0;
	return (0);
}

int	lock_key(int key, t_d *data)
{
	if (key == ESC)
		exit(0);
	else if (key == UP)
		data->w = 1;
	else if (key == DOWN)
		data->s = 1;
	else if (key == RIGHT)
		data->d = 1;
	else if (key == LEFT)
		data->a = 1;
	else if (key == R_RIGHT)
		data->r = 1;
	else if (key == R_LEFT)
		data->l = 1;
	return (0);
}
