/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:39:29 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/08 11:01:59 by jcauchet         ###   ########.fr       */
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
	int 	*f;
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
}	t_p;

// Parsing functions

void	parsing(char *map, t_p *params);
void	free_tab(char **tab);
void	style_error(char *map, t_p *params);
void	exit_and_print(int msg, char *str);
void	check_commas_num(char *str, int i, char *name);
void	check_values(int *values, char *name, char *str);
char	*char_param(char *name, char *str, int i);

#endif
