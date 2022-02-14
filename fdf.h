/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:16:24 by abellakr          #+#    #+#             */
/*   Updated: 2022/02/14 14:54:00 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef	FDF_H
# define	FDF_H

//****************************************** structs
typedef struct map
{
	int z;
	int	color;
}map;

typedef struct mlx
{
	void *mlx_ptr;
	void *window_ptr;
}mlx;

typedef struct fdf_var
{
	int lines;
	int colones;
	float x2;
	float y2;
	map **data_map;
	mlx *ptr;
} fdf_var;

//********************************************** libs
#include <mlx.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "./libft/libft.h"

//******************************************* prototypes
char	*ft_strdup2(char *s);
char	*get_next_line(int fd);
void	line_nb(int fd, fdf_var *number);
int		colone_nb(char *str);
int		atoi_hexa(char *number);
int		check_color(char *str);
void	read_line(char *line, map *line_in_map);
void 	store_map(int fd,char *fname, map **map_variables);
void	free_function(int index, map **tab);
void	free_function2(int index, char **tab);
int		alloc_function(fdf_var * number);
void	draw_function(fdf_var *vars);
void	check_function(fdf_var *vars);
void	index_check(int x, int y, fdf_var *vars);
void	dda_function(float x1, float y1, fdf_var *number);
//*************************************************** macos
# define ZOOM 25
# define  CENTRAL 210
#endif