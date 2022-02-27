/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:48:34 by abellakr          #+#    #+#             */
/*   Updated: 2022/02/27 01:48:45 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

/*-----------------------------------*/
void	check_function_bonus(t_fdf_var *vars)
{
	int	y;
	int	x;

	y = -1;
	while (++y < vars->lines)
	{
		x = -1;
		while (++x < vars->colones)
		{
			if (y < vars->lines - 1)
			{
				check_index1_bonus(x, y, vars);
				dda_function_bonus(vars);
			}
			if (x < vars->colones - 1)
			{
				check_index2_bonus(x, y, vars);
				dda_function_bonus(vars);
			}
		}
	}
}

/*------------------------------------------------------*/
void	check_index1_bonus(int x, int y, t_fdf_var *vars)
{
	vars->x1 = x;
	vars->y1 = y;
	vars->x2 = x;
	vars->y2 = y + 1;
	vars->z1 = vars->data_map[(int)vars->y1][(int)vars->x1].z;
	vars->z2 = vars->data_map[(int)vars->y2][(int)vars->x2].z;
}

/*------------------------------------------------------*/
void	check_index2_bonus(int x, int y, t_fdf_var *vars)
{
	vars->x1 = x;
	vars->y1 = y;
	vars->x2 = x + 1 ;
	vars->y2 = y;
	vars->z1 = vars->data_map[(int)vars->y1][(int)vars->x1].z;
	vars->z2 = vars->data_map[(int)vars->y2][(int)vars->x2].z;
}

/*------------------------------------------------------*/
void	dda_function_bonus(t_fdf_var *vars)
{
	int		color;
	float	steps;
	float	dx;
	float	dy;

	color = vars->data_map[(int)vars->y1][(int)vars->x1].color;
	if(vars->check_isometrie == 0)
		isometrie_bonus(vars);
	centrage_bonus(vars);
	zoom_bonus(vars);
	rotation_bonus(vars);
	dx = vars->x2 - vars->x1;
	dy = vars->y2 - vars->y1;
	if (fabsf(dx) > fabsf(dy))
		steps = fabsf(dx);
	else
		steps = fabsf(dy);
	dx /= steps;
	dy /= steps;
	while ((int)(vars->x1 - vars->x2) || (int)(vars->y1 - vars->y2))
	{
		my_mlx_pixel_put_bonus(vars->x1 + vars->x_offset + vars->x_translation,\
		 vars->y1 + vars->y_offset + vars->y_translation, vars, color);
		vars->x1 += dx;
		vars->y1 += dy;
	}
}
