/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:59:55 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/09 15:22:25 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

char	**dup_tab(char **tab)
{
	int		i;
	char	**new;

	if (!tab)
		return (NULL);
	i = 0;
	while (tab[i])
		i++;
	new = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (tab[i])
	{
		new[i] = ft_strdup(tab[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}

void	check_walls(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		check_h(tab[i++]);
	// i = 0;
	// while (tab[i])
	// 	check_v(tab[i++]);
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
					exit_and_print(13);
				i++;
			}
			if (!tab[i])
				return ;
		}
		i++;
	}
}

void	map_error(char **tab, int fd)
{
	char	*str;
	
	while (1)
	{
		str = get_next_line(fd);
		if (!str && !tab)
			exit_and_print(12);
		if (!str)
			break ;
		tab = add_tab(tab, str);
	}
	check_empty_lines(tab);
	print_tab(tab);
	check_walls(tab);
}
