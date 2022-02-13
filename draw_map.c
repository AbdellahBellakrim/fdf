/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:48:34 by abellakr          #+#    #+#             */
/*   Updated: 2022/02/13 19:25:58 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//********************************************************* draw funtion
void	draw_function(fdf_var *vars)
{
	int y;
	int x;

	y = 0;
	vars->ptr = (mlx *)malloc(sizeof(mlx));
	vars->ptr->mlx_ptr = mlx_init();
	vars->ptr->window_ptr = mlx_new_window(vars->ptr->mlx_ptr, 2050, 1500, "fdf");
	while(y < vars->lines)
	{
		x = 0;
		while(x < vars->colones)
		{
			if(y < vars->lines - 1)
			{
				vars->x2 = x;
				vars->y2 = y + 1;
				dda_function(x, y,vars);
			}
			if(x < vars->colones - 1)
			{
				vars->x2 = x + 1 ;
				vars->y2 = y;		
				dda_function(x, y, vars);
			}
			// if(vars->data_map[(int)y][(int)x].z == 0)
			// 	printf("%d  ", vars->data_map[(int)y][(int)x].z);
			// else
			// 	printf("%d ", vars->data_map[(int)y][(int)x].z);
			x++;
		}
		//printf("\n");
		y++;
	}
	mlx_loop(vars->ptr->mlx_ptr);
}
//******************************************************** dda algorithm
void	dda_function(float x1, float y1, fdf_var *vars)
{
	int		color;
	float	dx;
	float	dy;
	float	steps;
	int z1;
	int 	z2;


	color = vars->data_map[(int)y1][(int)x1].color;
	z2 = vars->data_map[(int)vars->y2][(int)vars->x2].z;
	z1 = vars->data_map[(int)y1][(int)x1].z;

	//****************************************** 3D
	x1 = (x1 - y1) * cos(1.085);
	y1 = (x1 + y1) * sin(1.085) - z1;
	vars->x2 = (vars->x2 - vars->y2) * cos(1.085);
	vars->y2 = (vars->x2 + vars->y2) * sin(1.085) - z2;
	//*********************************** zoom
	x1 *= ZOOM;
	y1 *= ZOOM;
	vars->x2 *= ZOOM;
	vars->y2 *= ZOOM;
	
	//*************************************** central
	x1 += CENTRAL;
	y1 += CENTRAL;
	vars->x2 += CENTRAL;
	vars->y2 += CENTRAL;

	dx = vars->x2 - x1;
	dy = vars->y2 - y1;

	if(fabsf(dx) > fabsf(dy))
		steps = fabsf(dx);
	else
		steps = fabsf(dy);
	dx /= steps;
	dy /= steps;
	while((int)(x1 - vars->x2) || (int)(y1 - vars->y2))
	{
		mlx_pixel_put(vars->ptr->mlx_ptr, vars->ptr->window_ptr, x1, y1, color);
		x1 += dx;
		y1 += dy;
	}
}
// having truble with z for printing 3D