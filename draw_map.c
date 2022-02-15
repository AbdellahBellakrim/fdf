/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:48:34 by abellakr          #+#    #+#             */
/*   Updated: 2022/02/15 18:32:52 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//********************************************************* print
void	draw_function(fdf_var *vars)
{
	vars->ptr = (mlx *)malloc(sizeof(mlx));
	vars->ptr->mlx_ptr = mlx_init();
	
	vars->ptr->window_ptr = mlx_new_window(vars->ptr->mlx_ptr,WEIGHT ,HEIGH, "fdf");
	vars->ptr->image_ptr = mlx_new_image(vars->ptr->mlx_ptr,WEIGHT ,HEIGH); 
	vars->ptr->buffer = mlx_get_data_addr(vars->ptr->image_ptr, &vars->ptr->bpp, &vars->ptr->line_lenght, &vars->ptr->endian);
	
	check_function(vars);
	mlx_put_image_to_window(vars->ptr->mlx_ptr,vars->ptr->window_ptr,vars->ptr->image_ptr, 0 ,0);
	mlx_loop(vars->ptr->mlx_ptr);
}
//********************************************************* check lines and colones
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
		}
	}
}
//******************************************************** dda algorithm
void	dda_function(float x1, float y1, fdf_var *vars)
{
	int		color;
	float	dx;
	float	dy;
	float	steps;
	int z[2];



	color = vars->data_map[(int)y1][(int)x1].color;
	z[1] = vars->data_map[(int)vars->y2][(int)vars->x2].z;
	z[0] = vars->data_map[(int)y1][(int)x1].z;

	//#################################### zoom
	x1 *= ZOOM;
	y1 *= ZOOM;
	vars->x2 *= ZOOM;
	vars->y2 *= ZOOM;
	//####################################3d
	x1 = (x1 - y1) * cos(0.523599);
	y1 = (x1 + y1) * sin(0.523599) - z[0];
	vars->x2 = (vars->x2 - vars->y2) * cos(0.523599);
	vars->y2 = (vars->x2 + vars->y2) * sin(0.523599) - z[1];
	

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
		//mlx_pixel_put(vars->ptr->mlx_ptr,vars->ptr->window_ptr, x1, y1, color);
		my_mlx_pixel_put(x1 + CENTRAL, y1 + CENTRAL, vars, color);
		x1 += dx;
		y1 += dy;
	}
}
//********************************************************** mlx_handle_image
void	my_mlx_pixel_put(float x1, float y1, fdf_var *vars, int color)
{
	char	*dst;
	if(((int)x1 >= 0 && (int)x1 < WEIGHT) && ((int)y1 >= 0 && (int)y1 < HEIGH))
	{
		

		dst = vars->ptr->buffer + ((int)y1 * vars->ptr->line_lenght + (int)x1 * (vars->ptr->bpp / 8));
		*(unsigned int*)dst = color;
	}
	
}