/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   style_error_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:15:39 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/06 19:30:16 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_commas(char *line)
{
	int	count;
	int	i;

	if (!line)
		return (ERROR);
	count = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		return (ERROR);
	return (1);
}

// Removeit
void	print_tab(char **tab)
{
	if (!tab)
	{
		printf("Tab cannot be printed\n");
		return ;
	}
	int	i;
	i = 0;
	while (tab[i])
		printf("'%s'\n", tab[i++]);
}

int	print_style_error(char *line, int msg)
{
	free(line);
	if (msg == 1)
		printf("Error\nThere's an unexpected NULL line in the file.\n");
	else if (msg == 2)
		printf("Error\nThere are too many commas.\n");
	return (ERROR);
}
