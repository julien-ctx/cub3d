/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:58:19 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/12 09:32:12 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_path_syntax(char *path)
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
			exit_and_print(PARAM);
		i++;
	}
}

char	*char_param(char *name, char *str, int i, void *ptr)
{
	char	*path;

	if (ptr)
		exit_and_print(DUP);
	while (str[i] && str[i] == ' ')
		i++;
	if (!str[i])
		exit_and_print(PARAM);
	if (str[i] != '.')
		exit_and_print(PARAM);
	if (str[++i] != '/')
		exit_and_print(PARAM);
	path = NULL;
	i++;
	while (str[i])
		path = ft_strjoin_char(path, str[i++]);
	check_path_syntax(path);
	free(name);
	return (path);
}

void	exit_and_print(char *str)
{
	printf("❌ ");
	printf("%s", str);
	exit (1);
}

void	check_commas_num(char *str, int i)
{
	int	count;

	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		else if ((str[i] < 48 || str[i] > 57) && str[i] != ' ')
			exit_and_print(RGB_INT);
		i++;
	}
	if (count != 2)
		exit_and_print(COMMAS);
}

char	**parsing(char *map, t_p *params, char **tab)
{
	int	fd;

	fd = param_error(map, params);
	return (map_error(tab, fd));
}
