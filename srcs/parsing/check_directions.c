/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_directions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 10:12:56 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/13 10:50:16 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_h_space(char *tab)
{
	int	i;
	int	boolean;

	i = 0;
	boolean = 0;
	while (tab[i])
	{
		if (i == 1 || tab[i] == '1')
			boolean = 0;
		if (tab[i] == ' ' && boolean)
			exit_and_print(WALLS);
		if (tab[i] == '0' && i > 0)
			if (tab[i - 1] == ' ')
				exit_and_print(WALLS);
		if (tab[i] == '0')
			boolean = 1;
		i++;
	}
}

void	check_h_zero(char *tab)
{
	int	i;
	int	boolean;

	i = 0;
	boolean = 0;
	while (tab[i])
	{
		if (tab[i] == '1')
			boolean = 1;
		if ((tab[i] == '0' && !boolean)
			|| (tab[i + 1] == '\0' && tab[i] == '0'))
			exit_and_print(WALLS);
		i++;
	}
}

void	check_v_space(char **tab)
{
	int	i;
	int	boolean;
	int	len;
	int	j;

	boolean = 0;
	len = ft_strlen(tab[0]);
	j = -1;
	while (++j < len)
	{
		i = -1;
		while (tab[++i])
		{
			if (i == 1 || tab[i][j] == '1')
				boolean = 0;
			if (tab[i][j] == ' ' && boolean)
				exit_and_print(WALLS);
			if (tab[i][j] == '0' && i > 0)
				if (tab[i - 1][j] == ' ')
					exit_and_print(WALLS);
			if (tab[i][j] == '0')
				boolean = 1;
		}
	}
}

void	check_v_zero(char **tab)
{
	int	i;
	int	boolean;
	int	len;
	int	j;

	boolean = 0;
	len = ft_strlen(tab[0]);
	j = -1;
	while (++j < len)
	{
		i = -1;
		while (tab[++i])
		{
			if (tab[i][j] == '1')
				boolean = 1;
			if (tab[i + 1])
				if ((tab[i][j] == '0' && !boolean) ||
					(tab[i + 1][j] == '\0' && tab[i][j] == '0'))
					exit_and_print(WALLS);
		}
	}
}

char	**check_walls(char **tab, t_p *params)
{
	int		i;
	char	**new;

	i = 0;
	while (tab[i])
	{
		check_h_space(tab[i]);
		check_h_zero(tab[i]);
		i++;
	}
	check_xpm(params, (int){0});
	new = resize_tab(tab);
	check_v_space(new);
	check_v_zero(new);
	return (new);
}
