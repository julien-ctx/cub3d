/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:37:39 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/19 13:00:01 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_orientation(t_d *data, char c)
{
	if (c == 'N')
	{
		data->dir_x = 0;
		data->dir_y = -1;
		return ;
	}
	if (c == 'S')
	{
		data->dir_x = 0;
		data->dir_y = 1;
		return ;
	}
	if (c == 'E')
	{
		data->dir_x = 1;
		data->dir_y = 0;
		return ;
	}
	data->dir_x = -1;
	data->dir_y = 0;
}

void	set_plane(t_d *data, char c)
{
	if (c == 'N' || c == 'S')
	{
		if (c == 'N')
			data->plane_x = 0.66;
		else
			data->plane_x = -0.66;
		data->plane_y = 0;
	}
	else
	{
		data->plane_x = 0;
		if (c == 'E')
			data->plane_y = 0.66;
		else
			data->plane_y = -0.66;
	}
}

void	player_pos_init(t_d *data, char **tab)
{
	int	i;
	int	j;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (tab[i][j] == 'N' || tab[i][j] == 'S' || tab[i][j] == 'E'
				|| tab[i][j] == 'W')
			{
				data->pos_x = j + 0.5;
				data->pos_y = i + 0.5;
				set_orientation(data, tab[i][j]);
				set_plane(data, tab[i][j]);
			}
		}
	}
}

void	keys_init(t_d *data)
{
	data->w = 0;
	data->a = 0;
	data->s = 0;
	data->d = 0;
	data->l = 0;
	data->r = 0;
}

void	init_data(char **tab, t_d *data, t_mlx *mlx, t_p *params)
{
	data->tab = tab;
	data->mlx = mlx;
	data->params = params;
	data->move_speed = MOVE_SPEED;
	player_pos_init(data, tab);
	keys_init(data);
}
