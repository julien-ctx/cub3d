/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:59:55 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/08 19:02:51 by jcauchet         ###   ########.fr       */
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

void	check_line_tab(char *str, int *player)
{
	int	i;
	
	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (!str[i])
		exit_and_print(10);
	if (str[i] != '1')
		exit_and_print(10);
	while (str[i])
	{
		if (str[i] == 'S' || str[i] == 'N' || str[i] == 'W' || str[i] == 'E')
			(*player)++;
		if (*player > 1)
			exit_and_print(11);
		if (str[i] != 'S' && str[i] != 'N' && str[i] != 'W' && str[i] != 'E'
			&& str[i] != '1' && str[i] != '0' && str[i] != ' ')
			exit_and_print(10);
		i++;
	}
	i--;
	while (i < -1 && str[i] == ' ')
		i--;
	if (i == -1)
		exit_and_print(10);
	if (str[i] != '1')
		exit_and_print(10);
}

void	map_error(char **tab, int fd)
{
	char	*str;
	int		player;
	int		i;
	
	
	player = 0;
	i = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break;
		if (!str[0])
		{
			free(str);
			continue ;
		}
		check_line_tab(str, &player);
		tab = add_tab(tab, str);
		i++;
	}
	print_tab(tab);
}
