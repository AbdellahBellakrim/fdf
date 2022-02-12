/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:48:34 by abellakr          #+#    #+#             */
/*   Updated: 2022/02/12 01:11:29 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//********************************************************* draw funtion
void	draw_function(fdf_var *number)
{
	int height;
	int weight;

	height = 0;
	while(height < number->lines_number)
	{
		weight = 0;
		while(weight < number->colones_number)
		{
			if(height < number->lines_number - 1)
			{
				number->x2 = weight + 1;
				number->y2 = height;
				// printf("\npoint:|%d,%d|------>",weight, height);
				// printf("next:|%d,%d|\n", number->x2,number->y2);
				dda_function(weight, height,number);
			}
			if(weight < number->colones_number - 1)
			{
				number->x2 = weight ;
				number->y2 = height + 1;
				// printf("\npoint:|%d,%d|------>",weight, height);
				// printf("next:|%d,%d|\n", number->x2,number->y2);				
				 dda_function(weight, height, number);
			}
			weight++;
		}
		height++;
	}
}
//******************************************************** dda algorithm
void	dda_function(int x1, int y1, fdf_var *number)
{
	int	dx;
	int dy;
	int steps;
	
	dx = number->x2 - x1;
	dy = number->y2 - y1;
	if(abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	dx /= steps;
	dy /= steps;
	while((x1 - number->x2) || (y1 - number->y2))
	{
		printf("\n|%d,%d|-->",x1, y1);
		//mlx_graphic(x1, y1, number);
		x1 += dx;
		y1 += dy;
		printf("|%d,%d|\n",x1, y1);
		
	}
}
//********************************************************* function for graphic handling
void	mlx_graphic(int x1, int y1, fdf_var *number)
{
	mlx	*ptr;
	int color;

	color = number->data_map[y1][x1].color;
	ptr = (mlx *)malloc(sizeof(mlx));
	ptr->mlx_ptr = mlx_init();
	ptr->window_ptr = mlx_new_window(ptr->mlx_ptr, 1000, 1000, "fdf");
	mlx_pixel_put(ptr->mlx_ptr, ptr->window_ptr, x1, y1, color);
	mlx_loop(ptr->window_ptr);
}
// prblm in mlx 