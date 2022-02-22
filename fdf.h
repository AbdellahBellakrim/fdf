/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:16:24 by abellakr          #+#    #+#             */
/*   Updated: 2022/02/22 13:00:36 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "./libft/libft.h"

# define HEIGH 1080
# define WEIGHT 1820

typedef struct map
{
	int	z;
	int	color;
}	t_map;

typedef struct mlx
{
	void	*mlx_ptr;
	void	*window_ptr;
	void	*image_ptr;
	char	*buffer;
	int		bpp;
	int		line_lenght;
	int		endian;
}	t_mlx;

typedef struct fdf_var
{
	float	x_offset;
	float	y_offset;
	float	zoom;
	int		z_offset;
	int		lines;
	int		colones;
	float	x1;
	float	y1;
	float	x2;
	float	y2;
	int		z1;
	int		z2;
	t_map	**data_map;
	t_mlx	*ptr;
}	t_fdf_var;

char	*ft_strdup2(char *s);
char	*get_next_line(int fd);
void	line_nb(int fd, t_fdf_var *number);
int		colone_nb(char *str);
int		atoi_hexa(char *number);
int		check_color(char *str);
void	read_line(char *line, t_map *line_in_map, t_fdf_var *number);
void	store_map(int fd, char *fname, t_map **map_variables, \
	t_fdf_var *number);
void	free_function(int index, t_map **tab);
void	free_function2(int index, char **tab);
int		alloc_function(t_fdf_var *number);
void	draw_function(t_fdf_var *vars);
void	check_function(t_fdf_var *vars);
void	check_index1(int x, int y, t_fdf_var *vars);
void	check_index2(int x, int y, t_fdf_var *vars);
void	dda_function(t_fdf_var *number);
void	isometrie(t_fdf_var *vars);
void	my_mlx_pixel_put(float x1, float y1, t_fdf_var *vars, int color);
void	check_args(int ac, char **av, t_fdf_var *number);
void	centrage(t_fdf_var *vars);
void	zoom(t_fdf_var *vars);
int		esc(int keycode, t_fdf_var *number);
void	check_extension(char *fname);
void	check_print(char **colones, int index);
void	check_map(t_fdf_var *number, int index);
int		close_cross(void *param);
void	split_cas_color(int index, char **colones, t_map *line_in_map);

#endif