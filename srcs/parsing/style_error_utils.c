/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   style_error_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:15:39 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/07 18:19:23 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	int_param_error(char *line, int i)
{
	int	j;
	int	count;

	j = i;
	count = 0;
	while (line[j])
	{
		if (line[j] == ',')
			count++;
		else if ((line[j] < 48 || line[j] > 57) && line[j] != ' ')
		{
			printf("Error\nYou can only use integers for C and R.\n");
			free(line);
			exit(1);
		}
		j++;
	}
	if (count != 2)
	{
		printf("Error\nNumber of commas is incorrect.\n");
		free(line);
		exit(1);
	}
}

int	return_error(int msg, char *str)
{
	if (msg == 1)
		printf("Error\nFile cannot be opened\n");
	else if (msg == 2)
		printf("Error\nMap syntax is incorrect.\n");
	else if (msg == 3)
		printf("Error\nLines filled with spaces are not handled.\n");
	else if (msg == 4)
		printf("Error\nMap description syntax is not correct.\n");
	else if (msg == 5)
		printf("Error\nYou need to specify map parameters correctly.\n");
	if (str)
		free(str);
	return (ERROR);
}

void	exit_error(int msg, char *str, char **tab)
{
	if (msg == 1)
		printf("Error\nUnexpected map file syntax.\n");
	else if (msg == 2)
		printf("Error\nThere are too much parameters for C or R.\n");
	else if (msg == 3)
		printf("Error\nTexture paths are incorrect.\n");
	else if (msg == 4)
		printf("Error\nTexture paths cannot contain spaces.\n");
	if (tab)
		free_tab(tab);
	if (str)
		free(str);
	exit(1);
}
