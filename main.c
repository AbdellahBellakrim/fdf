/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:54:42 by abellakr          #+#    #+#             */
/*   Updated: 2022/02/12 00:31:31 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//*************************************************** free function
void	free_function(int index, map **tab)
{
	int i;

	i = index - 1;
	while(i--)
		free(tab[i]);
	free(tab);
}
//*************************************** free funcction 2
void	free_function2(int index, char **tab)
{
	int i;

	i = index - 1;
	while(i--)
		free(tab[i]);
	free(tab);
}
//********************************************* allocate place for my data
int	alloc_function(fdf_var * number)
{
	int		index;
		
	index = -1;
	number->data_map = (map **)malloc(sizeof(map) * (number->lines_number + 1));
	if(!number->data_map)
		return(0);
	while (++index < number->lines_number)
	{
		number->data_map[index] = (map *)malloc(sizeof(map) * (number->colones_number + 1));
		if(!number->data_map[index])
			return(free_function(index, number->data_map),0);
	}
	return(1);
}
//********************************************** program
int main(int ac,char **av)
{
	int		fd;
	fdf_var	*number;

	if(ac != 2)
		return(0);
	number = (fdf_var *)malloc(sizeof(fdf_var));
	if(!number)
		return(0);
	fd = open(av[1],O_RDONLY); // get the number of lines of the map & the number of colones
	line_nb(fd, number);
	close(fd);
	alloc_function(number);
	store_map(fd, av[1] , number->data_map); // store the map 
	draw_function(number);
	
}
