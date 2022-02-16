/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:48:34 by abellakr          #+#    #+#             */
/*   Updated: 2022/02/17 00:14:31 by abellakr         ###   ########.fr       */
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
	vars->x1 *= ZOOM;
	vars->y1 *= ZOOM;
	vars->x2 *= ZOOM;
	vars->y2 *= ZOOM;
	//zoom;
	//centre;
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
		my_mlx_pixel_put(vars->x1 + CENTRAGE, vars->y1 + CENTRAGE, vars, color);
		vars->x1 += dx;
		vars->y1 += dy;
	}
}
/*--------------------------------------------------------------------------------------*/
void	isometrie(fdf_var *vars)
{
	int z1;
	int z2;
	z1 = 0;
	z2 = 0;
	if(vars->check_ac == 0)
	{
		z1 = vars->z1;
		z2 = vars->z2;
	}
	else if(vars->check_ac == 1)
	{
		if(vars->z1 != 0)
			z1 = vars->z_args;
		if(vars->z2 != 0)
			z2 = vars->z_args;
	}
	vars->x1 = (vars->x1 - vars->y1) * cos(0.523599);
	vars->y1 = (vars->x1 + vars->y1) * sin(0.523599) - z1;
	vars->x2 = (vars->x2 - vars->y2) * cos(0.523599);
	vars->y2 = (vars->x2 + vars->y2) * sin(0.523599) - z2;
}
// zoom b les cas dialo o arguments
// centrage b les cas dialo 
// esc botton 