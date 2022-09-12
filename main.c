/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:19:08 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/12 10:05:40 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	check_map_name(char **av)
{
	int	i;
	
	i = ft_strlen(av[1]);
	if (i < 4)
		exit_and_print(CUB);
	i--;
	if (av[1][i] != 'b' || av[1][i - 1] != 'u' || av[1][i - 2] != 'c'
		|| av[1][i - 3] != '.')
		exit_and_print(CUB);
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

void	print_params(t_p params)
{
	printf("----------------C---------------\n");
	for (int i = 0; i < 3; i++)
		printf("%d ", params.c[i]);
	printf("\n");
	printf("----------------F--------------\n");
	for (int i = 0; i < 3; i++)
		printf("%d ", params.f[i]);
	printf("\n");
	printf("----------------NO--------------\n");
	printf("'%s'\n", params.no);
	printf("----------------SO--------------\n");
	printf("'%s'\n", params.so);
	printf("----------------WE--------------\n");
	printf("'%s'\n", params.we);
	printf("----------------EA--------------\n");
	printf("'%s'\n", params.ea);
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
	// print_tab(tab);
	print_params(params);
	return (0);
}
