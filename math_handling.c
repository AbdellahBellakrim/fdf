/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:20:45 by abellakr          #+#    #+#             */
/*   Updated: 2022/02/24 18:34:22 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	int	diametre;

	diametre = sqrt(pow(vars->weight, 2) + pow(vars->height, 2));
	if (diametre > 875)
	{
		vars->x_offset = vars->weight - (diametre / 2.3);
		vars->y_offset = (diametre * 230) / vars->height ;
	}
	else
	{
		vars->x_offset = vars->weight / 2;
		vars->y_offset = diametre / 1.8;
	}
}

/*-----------------------------------------------------------------*/
void	my_zoom(t_fdf_var *vars)
{
	int		diamtre_map;

	diamtre_map = sqrt(pow(vars->colones, 2) + pow(vars->lines, 2));
	if (vars->zoom == 1)
	{
		if (diamtre_map < 100)
			vars->my_zoom = 25;
		else if (diamtre_map > 100 && diamtre_map < 250)
			vars->my_zoom = 3;
		else
			vars->my_zoom = 2;
	}
	else
		vars->my_zoom = vars->zoom;
}

/*-----------------------------------------------------------------*/
void	smooth_winddow(t_fdf_var *vars)
{
	int	x;
	int	y;

	x = sin(1) - cos(0.523599);
	y = cos(0.523599);
	
	
}

// /*-----------------------------------------------------------------*/
void	zoom(t_fdf_var *vars)
{
	vars->x1 *= vars->my_zoom;
	vars->y1 *= vars->my_zoom;
	vars->x2 *= vars->my_zoom;
	vars->y2 *= vars->my_zoom;
}

	// int		diamtre_map;

	// diamtre_map = sqrt(pow(vars->colones, 2) + pow(vars->lines, 2));
	// vars->weight = diamtre_map * vars->my_zoom * 1.5;
	// if (diamtre_map < 100 && diamtre_map > 70)
	// {
	// 	vars->height = diamtre_map * vars->my_zoom * 2.5;
	// }
	// else if (diamtre_map > 100 && diamtre_map < 250)
	// 	vars->height = diamtre_map * vars->my_zoom * 1.5;
	// else
	// 	vars->height = diamtre_map * vars->my_zoom;8