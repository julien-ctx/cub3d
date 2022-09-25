/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:50:08 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/25 16:02:48 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	destroy_win(int key, void *null)
{
	(void)null;
	(void)key;
	exit(0);
	return (0);
}

int	key_action(t_d *data)
{
	if (data->w)
		handle_up_down(data, UP);
	else if (data->s)
		handle_up_down(data, DOWN);
	if (data->r)
		handle_rot(data, R_RIGHT, ROT_SPEED);
	else if (data->l)
		handle_rot(data, R_LEFT, ROT_SPEED);
	if (data->a)
		handle_dir(data, LEFT);
	else if (data->d)
		handle_dir(data, RIGHT);
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
