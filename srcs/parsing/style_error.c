/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   style_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:38:31 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/06 16:49:47by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	*param_int(char **tab, int fd, char *line)
{
	int		i;
	int		*new;

	i = 1;
	new = NULL;
	while (tab[i])
		i++;
	if (i != 3)
	{
		printf("Error\nColor format for ground or ceiling is incorrect.\n");
		free(line);
		close(fd);
		exit(1);
	}
	new = malloc(3 * sizeof(int));
	while (tab[i])
	{
		new[i] = ft_atoi(tab[i]);
		i++;
	}
	return (new);
}

// char	*param_char(char *tab, int fd, char *line)
// {
// 	int	i;

// 	i = 1;
// 	while ()
// }

int	which_style(char **tab, t_p *params, char *line, int fd)
{
	if (!ft_strncmp(tab[0], "C", 1) && ft_strlen(tab[0]) == 1)
		params->c = param_int(tab, fd, line);
	else if (!ft_strncmp(tab[0], "R", 1) && ft_strlen(tab[0]) == 1)
		params->c = param_int(tab, fd, line);
	else if (!ft_strncmp(tab[0], "NO", 2) && ft_strlen(tab[0]) == 2)
		return (NO);
	else if (!ft_strncmp(tab[0], "SO", 2) && ft_strlen(tab[0]) == 2)
		return (SO);
	else if (!ft_strncmp(tab[0], "EA", 2) && ft_strlen(tab[0]) == 2)
		return (EA);
	else if (!ft_strncmp(tab[0], "WE", 2) && ft_strlen(tab[0]) == 2)
		return (WE);
	else
	{
		printf("Error\nSpecified style doesn't exist\n");
		return (ERROR);
	}
	return (1);
}

int	check_which_style(char *line, t_p *params, int fd)
{
	int	i;
	char **tab;

	i = 0;
	if (check_commas(line) == ERROR)
		return (print_style_error(line, 2));
	tab = ft_split(line, ',');
	print_tab(tab);
	exit(1);
	if (!tab)
		return (print_style_error(line, 1));
	if (!tab[0])
		return (print_style_error(line, 1));
	return (which_style(tab, params, line, fd));
}

int	style_error(char *map, t_p *params)
{
	char	*line;
	int		ret;
	int		fd;
	int		style;
	
	line = ft_strdup("");
	ret = 6;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (ERROR);
	while (line && ret)
	{
		if (line)
			free(line);
		line = get_next_line(fd);
		style = check_which_style(line, params, fd);
		if (style == ERROR)
		{
			close(fd);
			return (ERROR);
		}
		ret--;
		free(line);
		line = NULL;
	}
	close (fd);
	return (0);
}
