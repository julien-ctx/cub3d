/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_directions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 10:12:56 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/09 19:24:35 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	**dup_tab(char **tab)
{
	int		i;
	char	**new;

	if (!tab)
		return (NULL);
	i = 0;
	while (tab[i])
		i++;
	new = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (tab[i])
	{
		new[i] = ft_strdup(tab[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}

void	check_h(char *tab)
{
	int	i;
	int	boolean;
	
	i = 0;
	boolean = 0;
	while (tab[i])
	{
		if (i == 1 || tab[i] == '1')
			boolean = 0;
		if (tab[i] == ' ' && boolean)
			exit_and_print(14);
		if (tab[i] == '0' && i > 0)
			if (tab[i - 1] == ' ')
				exit_and_print(14);
		if (tab[i] == '0')
			boolean = 1;
		i++;
	}
}

void	check_v(char *tab)
{
	(void)tab;
}
