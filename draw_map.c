/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:48:34 by abellakr          #+#    #+#             */
/*   Updated: 2022/02/17 22:03:03 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*--------------------------------------------------------------------------------------*/
void	check_function(fdf_var *vars)
{
	int y;
	int x;

	y = -1;
	while(++y < vars->lines)
	{
		x = -1;
		while(++x < vars->colones)
		{
			if(y < vars->lines - 1)
			{
				check_index1(x, y, vars);
				dda_function(vars);
			}
			if(x < vars->colones - 1)
			{
				check_index2(x, y, vars);
				dda_function(vars);
			}
		}
	}
}
/*--------------------------------------------------------------------------------------*/
void	check_index1(int x, int y, fdf_var *vars)
{
	vars->x1 = x;
	vars->y1 = y;
	vars->x2 = x;
	vars->y2 = y + 1;
	vars->z1 = vars->data_map[(int)vars->y1][(int)vars->x1].z;
	vars->z2 = vars->data_map[(int)vars->y2][(int)vars->x2].z;
}
/*--------------------------------------------------------------------------------------*/
void	check_index2(int x, int y, fdf_var *vars)
{
	vars->x1 = x;
	vars->y1 = y;
	vars->x2 = x + 1 ;
	vars->y2 = y;
	vars->z1 = vars->data_map[(int)vars->y1][(int)vars->x1].z;
	vars->z2 = vars->data_map[(int)vars->y2][(int)vars->x2].z;
}
/*--------------------------------------------------------------------------------------*/
void	dda_function(fdf_var *vars)
{
	int		color;
	float	steps;
	float	dx;
	float	dy;
	
	color = vars->data_map[(int)vars->y1][(int)vars->x1].color;
	isometrie(vars);
	centrage(vars);
	zoom(vars);
	dx = vars->x2 - vars->x1;
	dy = vars->y2 - vars->y1;
	if(fabsf(dx) > fabsf(dy))
		steps = fabsf(dx);
	else
		steps = fabsf(dy);
	dx /= steps;
	dy /= steps;
	while((int)(vars->x1 - vars->x2) || (int)(vars->y1 - vars->y2))
	{
		my_mlx_pixel_put(vars->x1 + vars->x_offset, vars->y1 + vars->y_offset, vars, color);
		vars->x1 += dx;
		vars->y1 += dy;
	}
}