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

int	*int_param(char *line, int i)
{
	char	**tab;
	int		*values;

	int_param_error(line, i);
	tab = ft_split(&line[i], ',');
	if (!tab)
		exit_error(1, line, NULL);
	i = 0;
	while (tab[i])
		i++;
	if (i != 3)
		exit_error(2, line, tab);
	values = malloc(sizeof(int) * 3);
	i = -1;
	while (tab[++i])
		values[i] = ft_custom_atoi(tab[i]);
	free_tab(tab);
	return (values);
}

char	*char_params(char *line, int i)
{
	char	*str;
	int		j;

	str = NULL;
	while (line[i] && line[i] == ' ')
		i++;
	if (!line[i])
		exit_error(3, line, NULL);
	while (line[i])
	{
		if (line[i] == ' ')
		{
			j = i + 1;
			while (line[j])
				if (line[j++] != ' ')
					exit_error(4, line, NULL);
		}
		str = ft_strjoin_char(str, line[i]);
		i++;
	}
	if (str[0] != '.')
		exit_error(3, line, NULL);
	if (str[1])
		if (str[1] != '/')
			exit_error(3, line, NULL);
	return (str);
}

int	style_type(char *line, char *name, t_p *params, int i)
{
	if (!ft_strncmp("C", name, 1) && ft_strlen(name) == 1)
		params->c = int_param(line, i);
	else if (!ft_strncmp("R", name, 1) && ft_strlen(name) == 1)
		params->r = int_param(line, i);
	else if (!ft_strncmp("NO", name, 2) && ft_strlen(name) == 2)
		params->no = char_params(line, i);
	else if (!ft_strncmp("SO", name, 2) && ft_strlen(name) == 2)
		params->so = char_params(line, i);
	else if (!ft_strncmp("EA", name, 2) && ft_strlen(name) == 2)
		params->ea = char_params(line, i);
	else if (!ft_strncmp("WE", name, 2) && ft_strlen(name) == 2)
		params->we = char_params(line, i);
	else
	{
		printf("Error\nMap options syntax is incorrect\n");
		return (ERROR);
	}
	free(name);
	return (1);
}

int	check_line_syntax(char *line, t_p *params)
{
	int		i;
	char	*name;

	(void)params;
	if (!line)
		return (return_error(2, NULL));
	if (!line[0])
		return (-1);
	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (!line[i])
		return (return_error(3, NULL));
	name = NULL;
	while (line[i] && line[i] != ' ')
	{
		if (line[i] < 65 || line[i] > 90)
			return (return_error(4, name));
		name = ft_strjoin_char(name, line[i]);
		i++;
	}
	if (!line[i])
		return (return_error(5, name));
	if (style_type(line, name, params, i) == ERROR)
		return (ERROR);
	return (1);
}

int	style_error(char *map, t_p *params)
{
	int		fd;
	char	*str;
	int		styles;
	int		ret;

	styles = 6;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (return_error(1, NULL));
	str = ft_strdup("");
	while (str && styles)
	{
		if (str)
			free(str);
		str = get_next_line(fd);
		ret = check_line_syntax(str, params);
		if (ret == ERROR)
			return (ERROR);
		else if (ret != -1)
			styles--;
	}
	if (str)
		free(str);
	return (1);
}
