/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:27:21 by abellakr          #+#    #+#             */
/*   Updated: 2022/02/24 14:13:42 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*-----------------------------------------------------------*/
void	draw_function(t_fdf_var *vars)
{
	vars->ptr = (t_mlx *)malloc(sizeof(t_mlx));
	if (!vars->ptr)
	{
		perror ("somthing is wrong");
		exit (0);
	}
	vars->ptr->mlx_ptr = mlx_init();
	my_zoom(vars);
	smooth_winddow(vars);
	vars->ptr->window_ptr = \
	mlx_new_window (vars->ptr->mlx_ptr, vars->weight, vars->height, "fdf");
	vars->ptr->image_ptr = \
	mlx_new_image(vars->ptr->mlx_ptr, vars->weight, vars->height);
	vars->ptr->buffer = \
	mlx_get_data_addr (vars->ptr->image_ptr, &vars->ptr->bpp, \
	&vars->ptr->line_lenght, &vars->ptr->endian);
	check_function(vars);
	mlx_put_image_to_window (vars->ptr->mlx_ptr, vars->ptr->window_ptr, \
	vars->ptr->image_ptr, 0, 0);
	mlx_hook (vars->ptr->window_ptr, 2, 1L << 0, esc, vars);
	mlx_hook (vars->ptr->window_ptr, 17, 1L << 0, close_cross, vars);
	mlx_loop (vars->ptr->mlx_ptr);
}

/*------------------------------------------------------------------*/
void	my_mlx_pixel_put(float x1, float y1, t_fdf_var *vars, int color)
{
	char	*dst;

	if (((int)x1 >= 0 && (int)x1 < vars->weight) && \
	((int)y1 >= 0 && (int)y1 < vars->height))
	{
		dst = vars->ptr->buffer + ((int)y1 * vars->ptr->line_lenght \
		+ (int )x1 * (vars->ptr->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

/*----------------------------------------------------------------*/
int	esc(int keycode, t_fdf_var *number)
{
	if (keycode == 53)
	{
		mlx_destroy_image (number->ptr->mlx_ptr, number->ptr->image_ptr);
		mlx_destroy_window (number->ptr->mlx_ptr, number->ptr->window_ptr);
		exit (0);
	}
	return (0);
}

/*----------------------------------------------------------------*/
int	close_cross(void *param)
{
	(void)param;
	exit (0);
}
