/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:59:55 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/12 12:12:57 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	end_with_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

char	**add_tab(char **tab, char *str)
{
	char	**new;
	int		i;

	if (!tab)
	{
		tab = malloc(sizeof(char *) * 2);
		tab[0] = str;
		tab[1] = NULL;
		return (tab);
	}
	i = 0;
	while (tab[i])
		i++;
	new = malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (tab[i])
	{
		new[i] = ft_strdup(tab[i]);
		i++;
	}
	new[i] = str;
	new[i + 1] = NULL;
	free_tab(tab);
	return (new);
}

void	check_c(char **tab)
{
	int	player;
	int	i;
	int	j;

	player = 0;
	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (tab[i][j] == 'N' || tab[i][j] == 'S' || tab[i][j] == 'E'
				|| tab[i][j] == 'W')
					player++;
			else if (tab[i][j] != '0' && tab[i][j] != '1' && tab[i][j] != ' ')
				exit_and_print(CHARS);
		}
	}
	if (player != 1)
		exit_and_print(PLY);
}

void	check_empty_lines(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i][0])
			break ;
		i++;
	}
	while (tab[i])
	{
		if (!tab[i][0])
		{
			while (tab[i])
			{
				if (tab[i][0])
					exit_and_print(EMPTY);
				i++;
			}
			if (!tab[i])
				return ;
		}
		i++;
	}
}

char	**map_error(char **tab, int fd, t_p *params)
{
	char	*str;
	char	**new;

	while (1)
	{
		str = get_next_line(fd);
		if (!str && !tab)
			exit_and_print(NO_MAP);
		if (!str)
			break ;
		tab = add_tab(tab, str);
	}
	check_empty_lines(tab);
	check_c(tab);
	new = check_walls(tab, params);
	free_tab(tab);
	return (new);
}
