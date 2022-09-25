/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:25:32 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/25 20:25:33 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	check_map_name(char **av)
{
	int	i;
	int	fd;

	i = ft_strlen(av[1]);
	if (i < 4)
		exit_and_print(CUB);
	i--;
	if (av[1][i] != 'b' || av[1][i - 1] != 'u' || av[1][i - 2] != 'c'
		|| av[1][i - 3] != '.')
		exit_and_print(CUB);
	fd = open(av[1], O_DIRECTORY);
	if (fd > -1)
		exit_and_print(MAP_DIR);
}

int	args_error(int ac, char **av)
{
	int	i;

	if (ac != 2)
		return (ERROR);
	i = 0;
	while (av[1][i])
		i++;
	i--;
	if (ft_strlen(av[1]) < 4)
		return (ERROR);
	check_map_name(av);
	return (0);
}

void	params_init(t_p *params)
{
	params->c = NULL;
	params->f = NULL;
	params->ea = NULL;
	params->no = NULL;
	params->so = NULL;
	params->we = NULL;
}

int	main(int ac, char **av)
{
	t_p		params;
	char	**tab;

	if (args_error(ac, av) == ERROR)
		exit_and_print(ARGS);
	params_init(&params);
	tab = NULL;
	tab = parsing(av[1], &params, tab);
	raycasting(tab, params);
	return (0);
}
