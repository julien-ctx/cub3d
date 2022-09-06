/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:39:29 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/06 19:25:34 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# define ERROR -1
# define C 42
# define R 43
# define NO 44
# define SO 45
# define EA 46
# define WE 47

# include <OpenGL/gl.h>
# include "../srcs/minilibx/mlx.h"
# include "../srcs/minilibx/mlx_opengl.h"
# include "../srcs/minilibx/mlx_png.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h> 
# include <math.h>
# include "../srcs/gnl/get_next_line.h"
# include "../srcs/libft/libft.h"

typedef struct params
{
	int 	*c;
	int 	*r;
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
}	t_p;

// Parsing functions

int		parsing(char *map);
void	free_tab(char **tab);
int		print_style_error(char *line, int msg);
int		style_error(char *map, t_p *params);
void	print_tab(char **tab);
int		check_commas(char *line);

#endif
