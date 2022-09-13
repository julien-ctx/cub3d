/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_only_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:55:37 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/13 10:56:49 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_only_spaces(char *str)
{
	int	i;
	
	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		if (str[i] != ' ')
			return (0);
	return (1);
}
