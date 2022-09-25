/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_once.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:14:34 by jcauchet          #+#    #+#             */
/*   Updated: 2022/08/30 14:12:14 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**without_value(char *first)
{
	char	**tab;

	tab = malloc(sizeof(char *) * 3);
	tab[0] = first;
	tab[1] = ft_strdup("");
	tab[2] = NULL;
	return (tab);
}

char	**real_var(char *first, int i, char *str)
{
	char	**tab;
	char	*second;

	second = NULL;
	while (str[i])
	{
		second = ft_strjoin_char(second, str[i]);
		i++;
	}
	tab = malloc(sizeof(char *) * 3);
	tab[0] = first;
	tab[1] = second;
	tab[2] = NULL;
	return (tab);
}

char	**ft_split_once(char *str, char c)
{
	int		i;
	char	*first;
	char	**tab;

	first = NULL;
	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		first = ft_strjoin_char(first, str[i]);
		i++;
	}
	if (!str[i])
	{
		tab = malloc(sizeof(char *) * 2);
		tab[0] = first;
		tab[1] = NULL;
		return (tab);
	}
	if (str[i] == '=' && !str[i + 1])
		return (without_value(first));
	return (real_var(first, i + 1, str));
}
