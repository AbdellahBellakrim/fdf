/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 12:50:43 by abellakr          #+#    #+#             */
/*   Updated: 2022/02/27 14:15:06 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

/*------------------------------------------------------*/
void	rotation_x(t_fdf_var *vars)
{
	if (vars->x == 1)
	{
		vars->y1 = vars->y1 * cos(vars->o) \
		+ vars->z1 * sin(vars->o);
		vars->z1 = -vars->y1 * sin(vars->o) \
		+ vars->z1 * cos(vars->o);
		vars->y2 = vars->y2 * cos(vars->o) \
		+ vars->z2 * sin(vars->o);
		vars->z2 = -vars->y2 * sin(vars->o) \
		+ vars->z2 * cos(vars->o);
	}
}

/*------------------------------------------------------*/
void	rotation_y(t_fdf_var *vars)
{
	if (vars->y == 2)
	{
		vars->x1 = vars->x1 * cos(vars->o) \
		+ vars->z1 * sin(vars->o);
		vars->z1 = -vars->x1 * sin(vars->o) \
		+ vars->z1 * cos(vars->o);
		vars->x2 = vars->x2 * cos(vars->o) \
		+ vars->z2 * sin(vars->o);
		vars->z2 = -vars->x2 * sin(vars->o) \
		+ vars->z2 * cos(vars->o);
	}
}

/*------------------------------------------------------*/
void	rotation_z(t_fdf_var *vars)
{
	if (vars->z == 3)
	{
		vars->x1 = vars->x1 * cos(vars->o) \
		- vars->y1 * sin(vars->o);
		vars->y1 = vars->x1 * sin(vars->o) \
		- vars->y1 * cos(vars->o);
		vars->x2 = vars->x2 * cos(vars->o) \
		- vars->y2 * sin(vars->o);
		vars->y2 = vars->x2 * sin(vars->o) \
		- vars->y2 * cos(vars->o);
	}
}
