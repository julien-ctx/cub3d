/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:37:39 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/15 15:52:27 by jcauchet         ###   ########.fr       */
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

void	init_data(char **tab, t_d *data)
{
	data->time = 0;
	data->old_time = 0;
	player_pos_init(data, tab);
}
