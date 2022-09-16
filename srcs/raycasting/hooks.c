/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:04:59 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/16 02:04:31 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	handle_up(t_d *data)
{
	if (data->tab[(int)data->pos_y][(int)(data->pos_x + data->dir_x * data->move_speed)] != '1')
		data->pos_x += data->dir_x * data->move_speed;
	if (data->tab[(int)(data->pos_y + data->dir_y * data->move_speed)][(int)data->pos_x] != '1')
		data->pos_y += data->dir_y * data->move_speed;
	mlx_clear_window(data->mlx->ptr, data->mlx->win);
	// mlx_destroy_image(data->mlx->ptr, data->mlx->img.img_data);
	raycasting_loop(data->mlx, data->tab, data->params, data);
}

int	key(int key, void *param)
{
	(void)param;
	if (key == 53)
		exit(0);
	if (key == 126)
		handle_up(param);
	return (0);
}
