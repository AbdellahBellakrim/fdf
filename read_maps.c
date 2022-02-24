/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:19:19 by abellakr          #+#    #+#             */
/*   Updated: 2022/02/24 12:01:19 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*-------------------------------------------------*/
void	line_nb(int fd, t_fdf_var *number)
{
	int		index;
	char	*line;

	index = 0;
	line = get_next_line(fd);
	number->colones = colone_nb(line);
	while (line)
	{
		free (line);
		line = get_next_line(fd);
		++index;
	}
	free (line);
	number->lines = index;
}

/*---------------------------------------------------------*/
int	colone_nb(char *line)
{
	char	**colones;
	int		index;
	char	*str;

	index = 0;
	str = ft_strtrim(line, "\n");
	line = ft_strtrim(str, " ");
	colones = ft_split(line, ' ');
	while (colones[index] != NULL)
		index++;
	free(line);
	free(str);
	free_function2 (index, colones);
	return (index);
}

/*-------------------------------------------------------*/
void	read_line(char *line, t_map *line_in_map, t_fdf_var *number)
{
	int		index;
	char	**colones;

	index = -1;
	line = ft_strtrim(line, "\n");
	colones = ft_split(line, ' ');
	while (colones[++index])
	{
		check_print(colones, index);
		split_cas_color(index, colones, line_in_map);
	}
	check_map(number, index, colones);
	free(line);
	free(colones);
}

/*------------------------------------------------------------------*/
void	split_cas_color(int index, char **colones, t_map *line_in_map)
{
	char	**colored_colones;

	if (check_color(colones[index]))
	{
		colored_colones = ft_split(colones[index], ',');
		line_in_map[index].color = atoi_hexa(colored_colones[1]);
		if (ft_strncmp(colones[index], ",", 1) == 0)
			line_in_map[index].z = 0;
		else
			line_in_map[index].z = ft_atoi(colored_colones[0]);
		free(colored_colones[0]);
		free(colored_colones[1]);
		free(colored_colones);
	}
	else
	{
		if (ft_strncmp(colones[index], ",", 1) == 0)
			line_in_map[index].z = 0;
		else
			line_in_map[index].z = ft_atoi(colones[index]);
		line_in_map[index].color = atoi_hexa("0xFFFFFF");
	}
	free (colones[index]);
}

/*-----------------------------------------------------------*/
void	store_map(int fd, char *fname, t_map **map_variables, t_fdf_var *number)
{
	int		index;
	char	*line;

	fd = open(fname, O_RDONLY);
	if (fd < 0 || read(fd, 0, 1) == 0)
	{
		perror ("somtthing is wrong");
		exit (0);
	}
	index = 0;
	while (index < number->lines)
	{
		line = get_next_line(fd);
		read_line(line, map_variables[index], number);
		free (line);
		index++;
	}
	map_variables[index] = NULL;
	close (fd);
}
