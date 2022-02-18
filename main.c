/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:54:42 by abellakr          #+#    #+#             */
/*   Updated: 2022/02/18 18:39:56 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*------------------------------------------------------*/
void	check_args(int ac, char **av, fdf_var *number)
{
	if (ac == 2)
	{
		number->zoom = 1;
		number->z_offset = 1;
	}
	if (ac == 4)
	{
		number->zoom = ft_atoi(av[2]);
		number->z_offset = ft_atoi(av[3]);
	}
	if (number->zoom == 0 || number->z_offset == 0)
	{
		number->zoom = 1;
		number->z_offset = 1;
	}
}

/*------------------------------------------------------*/
int	alloc_function(fdf_var *number)
{
	int	index;

	index = -1;
	number->data_map = (map **)malloc(sizeof(map) * (number->lines + 1));
	if (!number->data_map)
		return (0);
	while (++index < number->lines)
	{
		number->data_map[index] = \
		(map *)malloc(sizeof(map) * (number->colones + 1));
		if (!number->data_map[index])
			return (free_function(index, number->data_map), 0);
	}
	return (1);
}

/*--------------------------------------------------------------*/
int	main(int ac, char **av)
{
	int		fd;
	fdf_var	*number;

	if (ac != 2 && ac != 4)
		return (perror("erros arguments "), 0);
	number = (fdf_var *)malloc(sizeof(fdf_var));
	if (!number)
		return (0);
	check_args (ac, av, number);
	fd = open (av[1], O_RDONLY);
	line_nb (fd, number);
	close (fd);
	alloc_function (number);
	store_map (fd, av[1], number->data_map);
	draw_function (number);
}
