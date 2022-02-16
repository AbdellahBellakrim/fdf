/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:48:34 by abellakr          #+#    #+#             */
/*   Updated: 2022/02/16 15:19:05 by abellakr         ###   ########.fr       */
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
//********************************************************* check index 1
void	check_index1(int x, int y, fdf_var *vars)
{
	vars->x1 = x;
	vars->y1 = y;
	vars->x2 = x;
	vars->y2 = y + 1;
}
//********************************************************* check index 2
void	check_index2(int x, int y, fdf_var *vars)
{
	vars->x1 = x;
	vars->y1 = y;
	vars->x2 = x + 1 ;
	vars->y2 = y;
}
//******************************************************** dda algorithm
void	dda_function(fdf_var *vars)
{
	int		color;
	float	steps;
	float	dxy[2];
	int z[2];

	z[1] = vars->data_map[(int)vars->y2][(int)vars->x2].z;
	z[0] = vars->data_map[(int)vars->y1][(int)vars->x1].z;
	color = vars->data_map[(int)vars->y1][(int)vars->x1].color;
	isometrie(vars, z);
	zoom(vars);
	dxy[0] = vars->x2 - vars->x1;
	dxy[1] = vars->y2 - vars->y1;
	if(fabsf(dxy[0]) > fabsf(dxy[1]))
		steps = fabsf(dxy[0]);
	else
		steps = fabsf(dxy[1]);
	dxy[0] /= steps;
	dxy[1] /= steps;
	while((int)(vars->x1 - vars->x2) || (int)(vars->y1 - vars->y2))
	{
		my_mlx_pixel_put(vars->x1 + CENTRAL, vars->y1 + CENTRAL, vars, color);
		vars->x1 += dxy[0];
		vars->y1 += dxy[1];
	}
}
//*************************************************** 3d isometric
void	isometrie(fdf_var *vars, int *z)
{
	vars->x1 = (vars->x1 - vars->y1) * cos(0.523599);
	vars->y1 = (vars->x1 + vars->y1) * sin(0.523599) - z[0];
	vars->x2 = (vars->x2 - vars->y2) * cos(0.523599);
	vars->y2 = (vars->x2 + vars->y2) * sin(0.523599) - z[1];
}
//***************************************************** zoom 
void	zoom(fdf_var *vars)
{
	vars->x1 *= ZOOM;
	vars->y1 *= ZOOM;
	vars->x2 *= ZOOM;
	vars->y2 *= ZOOM;
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
// zoom
// centrage