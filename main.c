/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:54:42 by abellakr          #+#    #+#             */
/*   Updated: 2022/02/17 00:05:27 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*--------------------------------------------------------------------------------------*/
void	check_ac(int ac, char **av,fdf_var *number)
{
	if(ac == 2 || ac == 4)
	{
		if(ac != 2 && (ft_atoi(av[2]) != 0 && ft_atoi(av[3]) != 0))
		{
			number->check_ac = 1;
			number->zoom_args = ft_atoi(av[2]);
			number->z_args = ft_atoi(av[3]);
			
		}
		else
			number->check_ac = 0;
	}
	else
	{
		free(number);
		perror("erros arguments ");
		exit(0);
	}
}
/*--------------------------------------------------------------------------------------*/
void	free_function(int index, map **tab)
{
	int i;

	i = index - 1;
	while(i--)
		free(tab[i]);
	free(tab);
}
/*--------------------------------------------------------------------------------------*/
void	free_function2(int index, char **tab)
{
	int i;

	i = index - 1;
	while(i--)
		free(tab[i]);
	free(tab);
}
/*--------------------------------------------------------------------------------------*/
int	alloc_function(fdf_var * number)
{
	int		index;
		
	index = -1;
	number->data_map = (map **)malloc(sizeof(map) * (number->lines + 1));
	if(!number->data_map)
		return(0);
	while (++index < number->lines)
	{
		number->data_map[index] = (map *)malloc(sizeof(map) * (number->colones + 1));
		if(!number->data_map[index])
			return(free_function(index, number->data_map),0);
	}
	return(1);
}
/*--------------------------------------------------------------------------------------*/
int main(int ac,char **av)
{
	int		fd;
	fdf_var	*number;
	
	number = (fdf_var *)malloc(sizeof(fdf_var));
	if(!number)
		return(0);
	check_ac(ac, av, number);
	fd = open(av[1],O_RDONLY); // get the number of lines of the map & the number of colones
	line_nb(fd, number);
	close(fd);
	alloc_function(number);
	store_map(fd, av[1] , number->data_map); // store the map 
	draw_function(number); // draw the map
}
