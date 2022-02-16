/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:27:21 by abellakr          #+#    #+#             */
/*   Updated: 2022/02/16 22:43:30 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*------------------------------------------------------------------------------------------------*/
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
/*-------------------------------------------------------------------------------------------------*/
void	my_mlx_pixel_put(float x1, float y1, fdf_var *vars, int color)
{
	char	*dst;
	if(((int)x1 >= 0 && (int)x1 < WEIGHT) && ((int)y1 >= 0 && (int)y1 < HEIGH))
	{
		dst = vars->ptr->buffer + ((int)y1 * vars->ptr->line_lenght + (int)x1 * (vars->ptr->bpp / 8));
		*(unsigned int*)dst = color;
	}
}