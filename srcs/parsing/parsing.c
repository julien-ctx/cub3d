/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:58:19 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/10 23:07:24 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	**parsing(char *map, t_p *params, char **tab)
{
	int	fd;

	param_error(map, params, &fd);
	return (map_error(tab, fd));
}
