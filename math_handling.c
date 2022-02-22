/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:20:45 by abellakr          #+#    #+#             */
/*   Updated: 2022/02/22 17:21:32 by abellakr         ###   ########.fr       */
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