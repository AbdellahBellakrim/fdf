/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:39:49 by abellakr          #+#    #+#             */
/*   Updated: 2022/02/27 03:15:58 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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
		number->my_zoom += 0.8;
	if (keycode == 31)
		number->my_zoom -= 0.8;	
//zoom in I : 34
// zoom out O: 31
}
/*----------------------------------------------------------------*/
void	key_z(int keycode, t_fdf_var *number)
{
	if (keycode == 69)
		number->z_offset += 0.1;	
	if (keycode == 78)
		number->z_offset -= 0.1;	
//  z + 69
// z - 78
}
/*----------------------------------------------------------------*/
void	key_translation(int keycode, t_fdf_var *number)
{
	if (keycode == 126)
		number->y_translation -= 50;
	if (keycode == 125)
		number->y_translation += 50;
	if (keycode == 124)
		number->x_translation += 50;
	if (keycode == 123)
		number->x_translation -= 50;
// traslation up : 126
// traslation down : 125
// traslation right : 124
// traslation left : 123
}
/*----------------------------------------------------------------*/
void	parallel_vue(int keycode, t_fdf_var *number)
{
	if(keycode == 35)
		number->check_isometrie = 1;
	if(keycode == 46)
		number->check_isometrie = 0;
// parallel p 35
// isometrie m 46
}
/*----------------------------------------------------------------*/
void	rotation_key(int keycode, t_fdf_var *number)
{
	if (keycode == 7)
	{
		number->x = 1;
		number->o += 0.4;
	}
	if (keycode == 16)
	{
		number->y = 1;
		number->o += 0.4;
	}
	if (keycode == 6)
	{
		number->z = 1;
		number->o += 0.4;
	}
	//x : 7
	//y : 16
	// z : 6
}
/*----------------------------------------------------------------*/
void	write_in_the_window(t_fdf_var *vars)
{
	mlx_string_put (vars->ptr->mlx_ptr, vars->ptr->window_ptr, 20, 20, 11268396, "click \
	I : ZOOM IN | O : ZOOM OUT");
	mlx_string_put (vars->ptr->mlx_ptr, vars->ptr->window_ptr, 30, 100, 11268396, "X | Y | Z : rotation");
	mlx_string_put (vars->ptr->mlx_ptr, vars->ptr->window_ptr, 30, 40, 11268396, "+ - : ALTITUDE");
	mlx_string_put (vars->ptr->mlx_ptr, vars->ptr->window_ptr, 30, 80, 11268396, "P & M : parallel_vue");
	mlx_string_put (vars->ptr->mlx_ptr, vars->ptr->window_ptr, 30, 60, 11268396, "ARROWS : TRANSLATION");
	mlx_string_put (vars->ptr->mlx_ptr, vars->ptr->window_ptr, 20, 1020, 11268396, "made by heybellakrim <3");

}