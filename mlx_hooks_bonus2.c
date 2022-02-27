/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks_bonus2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 13:03:36 by abellakr          #+#    #+#             */
/*   Updated: 2022/02/27 13:05:56 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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
}

/*----------------------------------------------------------------*/
void	parallel_vue(int keycode, t_fdf_var *number)
{
	if (keycode == 35)
		number->check_isometrie = 1;
	if (keycode == 46)
		number->check_isometrie = 0;
}

/*----------------------------------------------------------------*/
void	rotation_key(int keycode, t_fdf_var *number)
{
	if (keycode == 7)
	{
		number->y = 0;
		number->z = 0;
		number->x = 1;
		number->o += 0.4;
	}
	if (keycode == 16)
	{
		number->x = 0;
		number->z = 0;
		number->y = 2;
		number->o += 0.4;
	}
	if (keycode == 6)
	{
		number->x = 0;
		number->y = 0;
		number->z = 3;
		number->o += 0.4;
	}
}
// traslation up : 126
// traslation down : 125
// traslation right : 124
// traslation left : 123
// parallel p 35
// isometrie m 46
	//x : 7
	//y : 16
	// z : 6