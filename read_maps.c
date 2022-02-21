/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:19:19 by abellakr          #+#    #+#             */
/*   Updated: 2022/02/21 14:54:55 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*--------------------------------------------------------------------------------------*/
void	line_nb(int fd, fdf_var *number)
{
	int  index;
	char *line;
	
	index = 0;
	line  = get_next_line(fd);
	number->colones = colone_nb(line);
	while(line)
	{
		line = get_next_line(fd);
		++index;
	}
	number->lines = index;
	
}
/*--------------------------------------------------------------------------------------*/
int	colone_nb(char *line)
{
	char **colones;
	int index;

	index = 0;
	colones = ft_split(line, ' ');
	while(colones[index] != NULL)
		index++;
	return(index);
}
/*--------------------------------------------------------------------------------------*/
int check_color(char *str)
{
	int index;

	index = 0;
	while(str[index++])
	{
		if(ft_strchr(str, ','))
			return(1);
		index++;
	}
	return(0);
}
/*--------------------------------------------------------------------------------------*/
void	read_line(char *line, map *line_in_map, fdf_var *number)
{
	int index;
	char **colones;
	char **colored_colones;

	index = -1;
	colones = ft_split(line,' ');
	while(colones[++index])
	{
		if(ft_isprint(colones[index][0]) <= 0)
		{
			perror("oops invalid map");
			exit(0);
		}
		if(check_color(colones[index]))
		{
			colored_colones = ft_split(colones[index], ',');
			line_in_map[index].color = atoi_hexa(colored_colones[1]);
			line_in_map[index].z = ft_atoi(colored_colones[0]);
			free_function2(3, colored_colones);
		}
		else
		{
			line_in_map[index].z = ft_atoi(colones[index]);
			line_in_map[index].color = atoi_hexa("0xFFFFFF");
		}
		free(colones[index]);
	}
	if(index  != number->colones)
	{
		perror("oops invalid map short or long line");
		exit(0);
	}
	free(colones);
}
/*--------------------------------------------------------------------------------------*/
void store_map(int fd,char *fname, map **map_variables, fdf_var *number)
{
	int		index;
	char	*line;
	

	fd = open(fname, O_RDONLY);
	if(fd < 0 || read(fd, 0, 1)  == 0)
	{
		perror("somtthing is wrong");
		exit(0);
	}
	index = 0;
	while((line = get_next_line(fd)))
	{
		read_line(line, map_variables[index], number);
		index++;
	}
	map_variables[index] = NULL;
	close(fd);
}
// ,z
//tab and espace
//leaks
// norme 