/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_directions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 10:12:56 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/09 15:51:58 by jcauchet         ###   ########.fr       */
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
	(void)tab;
}

void	check_v(char *tab)
{
	(void)tab;
}
