/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:54:33 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/25 20:54:53 by jcauchet         ###   ########.fr       */
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
