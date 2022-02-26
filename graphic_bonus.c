/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:27:21 by abellakr          #+#    #+#             */
/*   Updated: 2022/02/26 17:55:54 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"


/*-----------------------------------------------------------*/
void	draw_function_bonus(t_fdf_var *vars)
{
	vars->ptr = (t_mlx *)malloc(sizeof(t_mlx));
	if (!vars->ptr)
	{
		perror ("somthing is wrong");
		exit (0);
	}
	vars->ptr->mlx_ptr = mlx_init();
	my_zoom_bonus(vars);
	vars->ptr->window_ptr = mlx_new_window (vars->ptr->mlx_ptr, WEIGHT, HEIGH, "fdf");
	vars->ptr->image_ptr = mlx_new_image(vars->ptr->mlx_ptr, WEIGHT, HEIGH);
	vars->ptr->buffer = mlx_get_data_addr (vars->ptr->image_ptr, &vars->ptr->bpp, &vars->ptr->line_lenght, &vars->ptr->endian);
	check_function_bonus(vars);
	mlx_put_image_to_window (vars->ptr->mlx_ptr, vars->ptr->window_ptr, vars->ptr->image_ptr, 0, 0);
	mlx_hook (vars->ptr->window_ptr, 2, 1L << 0, keyboard_bonus, vars);
	mlx_hook (vars->ptr->window_ptr, 17, 1L << 0, close_cross_bonus, vars);
	mlx_loop (vars->ptr->mlx_ptr);
}

/*----------------------------------------------------------------*/
int	keyboard_bonus(int key, t_fdf_var *number)
{
	esc(key, number);
	key_zoom(key, number);
	key_translation(key ,number);
	return (0);
}

/*----------------------------------------------------------------*/
void	esc(int keycode, t_fdf_var *number)
{
	if (keycode == 53)
	{
		mlx_destroy_image (number->ptr->mlx_ptr, number->ptr->image_ptr);
		mlx_destroy_window (number->ptr->mlx_ptr, number->ptr->window_ptr);
		exit (0);
	}
}

/*----------------------------------------------------------------*/
void	key_zoom(int keycode, t_fdf_var *number)
{
	if (keycode == 34)
		number->my_zoom += 6;
	if (keycode == 31)
		number->my_zoom -= 6;
	mlx_destroy_image(number->ptr->mlx_ptr, number->ptr->image_ptr);
	mlx_clear_window(number->ptr->mlx_ptr, number->ptr->window_ptr);
	number->ptr->mlx_ptr = mlx_init();
	number->ptr->image_ptr = mlx_new_image(number->ptr->mlx_ptr, WEIGHT, HEIGH);
	number->ptr->buffer = mlx_get_data_addr (number->ptr->image_ptr, &number->ptr->bpp, &number->ptr->line_lenght, &number->ptr->endian);
	check_function_bonus(number);
	mlx_put_image_to_window (number->ptr->mlx_ptr, number->ptr->window_ptr, number->ptr->image_ptr, 0, 0);	
}

/*----------------------------------------------------------------*/
void	key_translation(int keycode, t_fdf_var *number)
{
	if (keycode == 126)
		number->y1 += 1;
	if (keycode == 125)
		number->y1 -= 1;
	if (keycode == 124)
		number->x1 += 1;
	if (keycode == 123)
		number->x1 -= 1;
	// printf("\n%f\n", number->x1);
	// printf("\n%f\n", number->y1);
	mlx_destroy_image(number->ptr->mlx_ptr, number->ptr->image_ptr);
	mlx_clear_window(number->ptr->mlx_ptr, number->ptr->window_ptr);
	number->ptr->mlx_ptr = mlx_init();
	number->ptr->image_ptr = mlx_new_image(number->ptr->mlx_ptr, WEIGHT, HEIGH);
	number->ptr->buffer = mlx_get_data_addr (number->ptr->image_ptr, &number->ptr->bpp, &number->ptr->line_lenght, &number->ptr->endian);
	check_function_bonus(number);
	mlx_put_image_to_window (number->ptr->mlx_ptr, number->ptr->window_ptr, number->ptr->image_ptr, 0, 0);
}

/*----------------------------------------------------------------*/
int	close_cross_bonus(void *param)
{
	(void)param;
	exit (0);
}

/*------------------------------------------------------------------*/
void	my_mlx_pixel_put_bonus(float x1, float y1, t_fdf_var *vars, int color)
{
	char	*dst;

	if (((int)x1 >= 0 && (int)x1 < WEIGHT) && \
	((int)y1 >= 0 && (int)y1 < HEIGH))
	{
		dst = vars->ptr->buffer + ((int)y1 * vars->ptr->line_lenght \
		+ (int )x1 * (vars->ptr->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

//zoom in I : 34
// zoom out O: 31
// traslation up : 126
// traslation down : 125
// traslation right : 124
// traslation left : 123
