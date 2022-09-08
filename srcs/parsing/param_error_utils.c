/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_error_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:15:39 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/08 14:15:37 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_path_syntax(char *path, char *name, char *str)
{
	int	i;
	int	boolean;

	boolean = 0;
	i = 0;
	while (path[i])
	{
		if (!boolean && path[i] == ' ')
			boolean = 1;
		else if (boolean && path[i] != ' ')
		{
			free(name);
			free(path);
			exit_and_print(9, str);
		}
		i++;
	}
}

char	*char_param(char *name, char *str, int i, void *ptr)
{
	char	*path;

	if (ptr)
	{
		printf("Error\nDuplicated map parameters\n");
		free(name);
		free(str);
		exit(1);
	}
	while (str[i] && str[i] == ' ')
		i++;
	if (!str[i])
		exit_and_print(9, str);
	if (str[i] != '.')
		exit_and_print(9, str);
	if (str[++i] != '/')
		exit_and_print(9, str);
	path = NULL;
	i++;
	while (str[i])
		path = ft_strjoin_char(path, str[i++]);
	check_path_syntax(path, name, str);
	free(name);
	return (path);
}

void	exit_and_print(int msg, char *str)
{
	if (msg == 1)
		printf("Error\nOpening fd was unsuccessful.\n");
	if (msg == 2)
		printf("Error\nSome parameters are missing.\n");
	if (msg == 3)
		printf("Error\nLines filled with spaces are not handled.\n");
	if (msg == 4)
		printf("Error\nThere are missing values in map file params.\n");
	if (msg == 5)
		printf("Error\nThere are too many commas between parameters values.\n");
	if (msg == 6)
		printf("Error\nCeiling and floor can only receive int params\n");
	if (msg == 7)
		printf("Error\nCeiling and/or floor don't have RGB format.\n");
	if (msg == 8)
		printf("Error\nRGB values must be in [0, 255] range.\n");
	if (msg == 9)
		printf("Error\nMap parameters syntax is not correct.\n");
	if (str)
		free(str);
	exit(1);
}

void	check_values(int *values, char *name, char *str)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		if (values[i] < 0 || values[i] > 255)
		{
			free(values);
			free(name);
			exit_and_print(8, str);
		}
	}
}

void	check_commas_num(char *str, int i, char *name)
{
	int	count;

	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		else if ((str[i] < 48 || str[i] > 57) && str[i] != ' ')
		{
			free(name);
			exit_and_print(6, str);
		}	
		i++;
	}
	if (count != 2)
	{
		free(name);
		exit_and_print(5, str);
	}
}
