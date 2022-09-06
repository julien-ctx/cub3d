/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:19:08 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/06 14:38:14 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	syntax_error(int ac, char **av)
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
	// jcauchetcomment: check here if there's .cub at the end of the file's name.
	return (0);
}

int	main(int ac, char **av)
{
	if (syntax_error(ac, av) == ERROR)
	{
		printf("Error\nPlease use a correct format: ./cub3d map_name.cub\n");
		return (1);
	}
	if (parsing(av[1]) == ERROR)
		return (1);
	return (0);
}
