/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:39:49 by abellakr          #+#    #+#             */
/*   Updated: 2022/02/26 21:37:03 by abellakr         ###   ########.fr       */
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
