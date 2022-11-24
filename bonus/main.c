/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencaucheteux <juliencaucheteux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:25:32 by jcauchet          #+#    #+#             */
/*   Updated: 2022/11/24 11:40:25 by juliencauch      ###   ########.fr       */
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
	{
		close(fd);
		exit_and_print(MAP_DIR);
	}
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

int	main(int ac, char **av)
{
	t_p		params;
	char	**tab;

	if (args_error(ac, av) == ERROR)
		exit_and_print(ARGS);
	ft_bzero(&params, sizeof(params));
	tab = NULL;
	tab = parsing(av[1], &params, tab);
	raycasting(tab, params);
	return (0);
}
