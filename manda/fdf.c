/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:45:22 by abellakr          #+#    #+#             */
/*   Updated: 2022/02/26 17:54:48 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*------------------------------------------------------*/
int	alloc_function(t_fdf_var *number)
{
	int	index;

	index = -1;
	number->data_map = (t_map **)malloc(sizeof(t_map) * (number->lines + 1));
	if (!number->data_map)
		return (0);
	while (++index < number->lines)
	{
		number->data_map[index] = \
		(t_map *)malloc(sizeof(t_map) * (number->colones + 1));
		if (!number->data_map[index])
			return (free_function(index, number->data_map), 0);
	}
	return (1);
}

/*--------------------------------------------------------------*/
int	main(int ac, char **av)
{
	int			fd;
	t_fdf_var	*number;

	if (ac != 2 && ac != 4)
		return (perror("erros arguments "), 0);
	check_extension(av[1]);
	number = (t_fdf_var *)malloc(sizeof(t_fdf_var));
	if (!number)
		return (0);
	check_args (ac, av, number);
	fd = open (av[1], O_RDONLY);
	if (fd < 0 || read(fd, 0, 1) == 0)
		return (perror("someting is wrong "), 0);
	line_nb (fd, number);
	close (fd);
	alloc_function (number);
	store_map (fd, av[1], number->data_map, number);
	draw_function (number);
}
