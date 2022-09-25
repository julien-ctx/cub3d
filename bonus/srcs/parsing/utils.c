/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:43:11 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/25 20:26:03 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	tab_size(char **tab)
{
	int	i;

	if (!tab)
		return (0);
	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	exit_and_print(char *str)
{
	printf("❌ ");
	printf("%s", str);
	exit (1);
}

int	max_tab_len(char **tab)
{
	int	i;
	int	len;

	len = 0;
	if (!tab)
		return (0);
	i = -1;
	while (tab[++i])
		if (ft_strlen(tab[i]) > len)
			len = ft_strlen(tab[i]);
	return (len);
}

char	**resize_tab(char **tab)
{
	char	**new;
	int		i;
	int		len;
	int		j;

	len = max_tab_len(tab);
	new = malloc(sizeof(char *) * (tab_size(tab) + 1));
	if (!new)
		return (NULL);
	i = -1;
	while (tab[++i])
	{
		j = -1;
		new[i] = malloc(sizeof(char) * (ft_strlen(tab[i]) + 1));
		if (!new[i])
			return (NULL);
		while (tab[i][++j])
			new[i][j] = tab[i][j];
		new[i][j] = '\0';
		if (j < len)
			while (j++ < len)
				new[i] = ft_strjoin_char(new[i], ' ');
	}
	new[i] = NULL;
	return (new);
}

void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
