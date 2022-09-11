/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencaucheteux <juliencaucheteux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:58:19 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/11 16:51:44 by juliencauch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	**parsing(char *map, t_p *params, char **tab)
{
	int fd;

	fd = param_error(map, params);
	return (map_error(tab, fd));
}
