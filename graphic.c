/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:27:21 by abellakr          #+#    #+#             */
/*   Updated: 2022/02/22 12:43:13 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*-----------------------------------------------------------*/
void	draw_function(t_fdf_var *vars)
{
	vars->ptr = (t_mlx *)malloc(sizeof(t_mlx));
	if (!vars->ptr)
	{
		perror ("somthing is wrong");
		exit(0);
	}
	vars->ptr->mlx_ptr = mlx_init();
	vars->ptr->window_ptr = \
	mlx_new_window (vars->ptr->mlx_ptr, WEIGHT, HEIGH, "fdf");
	vars->ptr->image_ptr = \
	mlx_new_image(vars->ptr->mlx_ptr, WEIGHT, HEIGH);
	vars->ptr->buffer = \
	mlx_get_data_addr (vars->ptr->image_ptr, &vars->ptr->bpp, \
	&vars->ptr->line_lenght, &vars->ptr->endian);
	check_function (vars);
	mlx_put_image_to_window (vars->ptr->mlx_ptr, vars->ptr->window_ptr, \
	vars->ptr->image_ptr, 0, 0);
	mlx_hook (vars->ptr->window_ptr, 2, 1L << 0, esc, vars);
	mlx_hook (vars->ptr->window_ptr, 17, 1L << 0, close_cross, vars);
	mlx_loop (vars->ptr->mlx_ptr);
}

/*------------------------------------------------------------------*/
void	my_mlx_pixel_put(float x1, float y1, t_fdf_var *vars, int color)
{
	char	*dst;

	if (((int)x1 >= 0 && (int)x1 < WEIGHT) && \
	((int)y1 >= 0 && (int)y1 < HEIGH))
	{
		dst = vars->ptr->buffer + ((int)y1 * vars->ptr->line_lenght \
		+ (int)x1 * (vars->ptr->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

/*-------------------------------------------------------------*/
void	isometrie(t_fdf_var *vars)
{
	int	z1;
	int	z2;
	
	z1 = vars->z1 * vars->z_offset;
	z2 = vars->z2 * vars->z_offset;
	
	vars->x1 = (vars->x1 - vars->y1) * cos(0.523599);
	vars->y1 = (vars->x1 + vars->y1) * sin(0.523599) - z1;
	vars->x2 = (vars->x2 - vars->y2) * cos(0.523599);
	vars->y2 = (vars->x2 + vars->y2) * sin(0.523599) - z2;
}

/*----------------------------------------------------------------*/
void	centrage(t_fdf_var *vars)
{
	int diametre;

	diametre = sqrt(pow(WEIGHT,2) + pow(HEIGH,2));
	vars->x_offset =  WEIGHT  - (diametre / 2.3);
	vars->y_offset = (diametre * 230)  / HEIGH ;
}

/*-----------------------------------------------------------------*/
void	zoom(t_fdf_var *vars)
{
	int diamtre_map;
	float zoom;
	diamtre_map = sqrt(pow(vars->colones,2) + pow(vars->lines,2));
	if(vars->zoom == 1)
	{
		if(diamtre_map < 100)
			zoom = 25;
		else if(diamtre_map > 100 && diamtre_map < 250)
			zoom = 3;
		else
			zoom = 2;
	}
	else
		zoom = vars->zoom;
	vars->x1 *= zoom;
	vars->y1 *= zoom;
	vars->x2 *= zoom;
	vars->y2 *= zoom;
}

/*----------------------------------------------------------------*/
int	esc(int keycode, t_fdf_var *number)
{
	if(keycode == 53)
	{
		mlx_destroy_image (number->ptr->mlx_ptr,number->ptr->image_ptr);
		mlx_destroy_window (number->ptr->mlx_ptr,number->ptr->window_ptr);
		exit(0);
	}
	return(0);
}
/*----------------------------------------------------------------*/
int close_cross(void *param)
{
	(void)param;
    exit(0);
}