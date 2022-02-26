/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:16:24 by abellakr          #+#    #+#             */
/*   Updated: 2022/02/26 23:38:29 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

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
	int		lines;
	int		colones;
	float	x_offset;
	float	y_offset;
	float	x_translation;
	float	y_translation;
	float	z_offset;
	float	my_zoom;
	float	zoom;
	float	x1;
	float	y1;
	float	x2;
	float	y2;
	int		z1;
	int		z2;
	int		check_isometrie;
	t_map	**data_map;
	t_mlx	*ptr;
}	t_fdf_var;

char	*ft_strdup2_bonus(char *s);
char	*get_next_line_bonus(int fd);
void	line_nb_bonus(int fd, t_fdf_var *number);
int		colone_nb_bonus(char *str);
int		atoi_hexa_bonus(char *number);
int		check_color_bonus(char *str);
void	read_line_bonus(char *line, t_map *line_in_map, t_fdf_var *number);
void	store_map_bonus(int fd, char *fname, t_map **map_variables, \
	t_fdf_var *number);
void	free_function_bonus(int index, t_map **tab);
void	free_function2_bonus(int index, char **tab);
int		alloc_function_bonus(t_fdf_var *number);
void	draw_function_bonus(t_fdf_var *vars);
void	check_function_bonus(t_fdf_var *vars);
void	check_index1_bonus(int x, int y, t_fdf_var *vars);
void	check_index2_bonus(int x, int y, t_fdf_var *vars);
void	dda_function_bonus(t_fdf_var *number);
void	isometrie_bonus(t_fdf_var *vars);
void	my_mlx_pixel_put_bonus(float x1, float y1, t_fdf_var *vars, int color);
void	check_args_bonus(int ac, char **av, t_fdf_var *number);
void	centrage_bonus(t_fdf_var *vars);
void	check_extension_bonus(char *fname);
void	check_print_bonus(char **colones, int index);
void	check_map_bonus(t_fdf_var *number, int index, char **colones);
int		close_cross_bonus(void *param);
void	split_cas_color_bonus(int index, char **colones, t_map *line_in_map);
int		handle_cases_atoh_bonus(int sum, char *number);
void	my_zoom_bonus(t_fdf_var *vars);
void	zoom_bonus(t_fdf_var *vars);
int		keyboard_bonus(int key, t_fdf_var *number);
void	esc(int keycode, t_fdf_var *number);
void	key_zoom(int keycode, t_fdf_var *number);
void	key_z(int keycode, t_fdf_var *number);
void	key_translation(int keycode, t_fdf_var *number);
void	parallel_vue(int keycode, t_fdf_var *number);
#endif