/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:04:48 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/08 14:21:30 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	*retrieve_val(char *str, char *name, int i)
{
	int		*values;
	char	**tab;

	tab = ft_split(&str[i], ',');
	i = 0;
	while (tab[i])
		i++;
	if (i != 3)
	{
		free(name);
		exit_and_print(7, str);
	}
	values = malloc(sizeof(int) * 3);
	i = 0;
	while (tab[i])
	{
		values[i] = ft_custom_atoi(tab[i]);
		i++;
	}
	check_values(values, name, str);
	return (values);
}

int	*int_param(char *name, char *str, int i, void *ptr)
{
	int	*values;

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
	{
		free(name);
		exit_and_print(4, str);
	}
	check_commas_num(str, i, name);
	values = retrieve_val(str, name, i);
	free(name);
	return (values);
}

void	param_val(char *name, char *str, t_p *params, int i)
{
	if (!ft_strncmp(name, "C", 1) && ft_strlen(name) == 1)
		params->c = int_param(name, str, i, params->c);
	else if (!ft_strncmp(name, "F", 1) && ft_strlen(name) == 1)
		params->f = int_param(name, str, i, params->f);
	else if (!ft_strncmp(name, "NO", 2) && ft_strlen(name) == 2)
		params->no = char_param(name, str, i, params->no);
	else if (!ft_strncmp(name, "SO", 2) && ft_strlen(name) == 2)
		params->so = char_param(name, str, i, params->so);
	else if (!ft_strncmp(name, "EA", 2) && ft_strlen(name) == 2)
		params->ea = char_param(name, str, i, params->ea);
	else if (!ft_strncmp(name, "WE", 2) && ft_strlen(name) == 2)
		params->we = char_param(name, str, i, params->we);
	else
	{
		free(name);
		exit_and_print(10, str);
	}
}

void	handle_param(char *str, t_p *params, int *rep)
{
	int		i;
	char	*name;

	i = 0;
	if (!str[0])
		return ;
	while (str[i] && str[i] == ' ')
		i++;
	if (!str[i])
		exit_and_print(3, str);
	name = NULL;
	while (str[i] && str[i] != ' ' && (str[i] >= 65 && str[i] <= 90))
		name = ft_strjoin_char(name, str[i++]);
	if (!str[i])
	{
		free(name);
		exit_and_print(4, str);
	}
	if ((str[i] < 65 || str[i] > 90) && str[i] != ' ')
		exit_and_print(9, str);
	param_val(name, str, params, i);
	(*rep)++;
}

void	param_error(char *map, t_p *params, int *fd)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	*fd = open(map, O_RDONLY);
	if (*fd < 0)
		exit_and_print(1, NULL);
	while (i < 6)
	{
		str = get_next_line(*fd);
		if (!str)
			break ;
		handle_param(str, params, &i);
		free(str);
	}
	if (i != 6)
		exit_and_print(2, NULL);
}
