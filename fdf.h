/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:16:24 by abellakr          #+#    #+#             */
/*   Updated: 2022/02/17 18:28:02 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef	FDF_H
# define	FDF_H
/*--------------------------------------------------------------------------------------*/
typedef struct map
{
	int z;
	int	color;
}map;

typedef struct mlx
{
	void *mlx_ptr;
	void *window_ptr;
	void *image_ptr;
	char *buffer;
	int bpp;
	int line_lenght;
	int endian;
	
}mlx;

typedef struct fdf_var
{
	float	x_offset;
	float	y_offset;
	float	zoom;
	int	z_offset;
	/*----------------*/
	int lines;
	int colones;
	float x1;
	float y1;
	float x2;
	float y2;
	int	z1;
	int z2;
	map **data_map;
	mlx *ptr;
} fdf_var;


/*--------------------------------------------------------------------------------------*/

#include <mlx.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "./libft/libft.h"

/*--------------------------------------------------------------------------------------*/

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
void	check_index1(int x, int y, fdf_var *vars);
void	check_index2(int x, int y, fdf_var *vars);
void	dda_function(fdf_var *number);
void	isometrie(fdf_var *vars);
void	my_mlx_pixel_put(float x1, float y1, fdf_var *vars, int color);
void	check_args(int ac,char **av, fdf_var *number);
void	centrage(fdf_var *vars);
void	zoom(fdf_var *vars);
/*--------------------------------------------------------------------------------------*/
# define HEIGH 1080
# define WEIGHT 1820
#endif