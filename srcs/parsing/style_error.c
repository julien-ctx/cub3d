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

int	*param_int(char **tab, char *line)
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

int	which_style(char *str)
{
	int	style;

	style = ERROR;
	if (!ft_strncmp(str, "C", 1) && ft_strlen(str) == 1)
		style = C;
	else if (!ft_strncmp(str, "R", 1) && ft_strlen(str) == 1)
		style = R;
	else if (!ft_strncmp(str, "NO", 2) && ft_strlen(str) == 2)
		style = NO;
	else if (!ft_strncmp(str, "SO", 2) && ft_strlen(str) == 2)
		style = SO;
	else if (!ft_strncmp(str, "EA", 2) && ft_strlen(str) == 2)
		style = EA;
	else if (!ft_strncmp(str, "WE", 2) && ft_strlen(str) == 2)
		style = WE;
	free(str);
	if (style == ERROR)
		printf("Error\nSpecified style doesn't exist\n");
	return (style);
}

int	check_which_style(char *line, t_p *params)
{
	int		i;
	char 	**tab;
	char	*str;
	int		style;

	(void)params;
	str = NULL;
	i = 0;
	if (check_commas(line) == ERROR)
		return (print_style_error(line, 2));
	while (line[i] && line[i] == ' ')
		i++;
	while (line[i] && ft_isalpha(line[i]))
		str = ft_strjoin_char(str, line[i++]);
	tab = ft_split(&line[i], ',');
	print_tab(tab);
	exit(1);
	if (!tab)
		return (print_style_error(line, 1));
	if (!tab[0])
		return (print_style_error(line, 1));
	style = which_style(str);
	if (style == ERROR)
		return (ERROR);
	if (style == C || style == R)
		param_int(tab, line);
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
		style = check_which_style(line, params);
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
