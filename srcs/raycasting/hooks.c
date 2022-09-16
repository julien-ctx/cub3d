/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:04:59 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/16 14:54:46 by jcauchet         ###   ########.fr       */
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
	raycasting_loop(data->mlx, data->tab, data->params, data);
}

void	handle_down(t_d *data)
{
	if (data->tab[(int)data->pos_y][(int)(data->pos_x - data->dir_x * data->move_speed)] != '1')
		data->pos_x -= data->dir_x * data->move_speed;
	if (data->tab[(int)(data->pos_y - data->dir_y * data->move_speed)][(int)data->pos_x] != '1')
		data->pos_y -= data->dir_y * data->move_speed;
	// mlx_clear_window(data->mlx->ptr, data->mlx->win);
	raycasting_loop(data->mlx, data->tab, data->params, data);	
}

int	key_action(t_d *data)
{
	if (data->w)
		handle_up(data);
	if (data->s)
		handle_down(data);
	return (0);
}

int	press_key(int key, t_d *data)
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
	else if (key == LEFT)
		data->l = 1;
	return (0);
}
