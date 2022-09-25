/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:54:33 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/25 22:24:55 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	destroy_win(int key, void *null)
{
	(void)null;
	(void)key;
	exit(0);
	return (0);
}

void	mouse_rot(t_d *data)
{
	static int	old_mouse_x = WIDTH / 2;
	int			diff;

	mlx_mouse_get_pos(data->mlx->win, &data->mouse_x, &data->mouse_y);
	diff = old_mouse_x - data->mouse_x;
	if (data->mouse_x >= WIDTH)
	{
		mlx_mouse_move(data->mlx->win, WIDTH / 2, HEIGHT / 2);
		old_mouse_x = WIDTH / 2;
		return ;
	}
	else if (data->mouse_x <= 0)
	{
		mlx_mouse_move(data->mlx->win, WIDTH / 2, HEIGHT / 2);
		old_mouse_x = WIDTH / 2;
		return ;
	}
	if (diff == 0)
		return ;
	else if (diff < 0)
		handle_rot(data, R_RIGHT, MOUSE_SPEED * abs(diff) / MOUSE_COEF);
	else
		handle_rot(data, R_LEFT, MOUSE_SPEED * diff / MOUSE_COEF);
	old_mouse_x = data->mouse_x;
}

int	lock_mouse(int key, void *null)
{
	static int	state = 0;

	(void)null;
	if (key == R_CLICK)
	{
		if (!state)
		{
			mlx_mouse_show();
			state = 1;
		}
		else
		{
			mlx_mouse_hide();
			state = 0;
		}
	}
	return (0);
}
