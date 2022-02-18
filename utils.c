/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:31:10 by abellakr          #+#    #+#             */
/*   Updated: 2022/02/18 18:25:09 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*--------------------------------------*/
char	*ft_strdup2(char *s)
{
	int		i;
	char	*t;

	i = 0;
	while (s[i])
		i++;
	t = malloc(i + 1);
	i = 0;
	while (s[i])
	{
		t[i] = s[i];
		i++;
	}
	t[i] = 0;
	return (t);
}

/*--------------------------------------*/
char	*get_next_line(int fd)
{
	static char	*buffer_reminder;
	char		buff[1];
	char		line[1000000];
	int			i;
	int			n;

	buffer_reminder = 0;
	if (fd < 0)
		return (NULL);
	line[0] = 0;
	i = 0;
	while ((n = read(fd, buff, 1)) && (n > 0))
	{
		line[i++] = buff[0];
		line[i] = '\0';
		if (buff[0] == '\n')
			return (ft_strdup2(line));
	}
	if (!line[0])
		return (NULL);
	return (ft_strdup2(line));
}

/*---------------------------------------*/
int	atoi_hexa(char *number)
{
	int	i;
	int	j;
	int	sum;

	i = ft_strlen (number) - 1 ;
	j = 0;
	sum = 0;
	while (i > 1)
	{
		if (number[i] >= 'A' && number[i] <= 'F')
			sum = sum + (number[i] - 55) * pow(16, j);
		else if (number[i] >= 'a' && number[i] <= 'f')
			sum = sum + (number[i] - 87) * pow(16, j);
		else if (number[i] >= '0' && number[i] <= '9')
			sum = sum + (number[i] - 48) * pow(16, j);
		i--;
		j++;
	}
	return (sum);
}

/*-----------------------------------------------*/
void	free_function(int index, map **tab)
{
	int	i;

	i = index - 1;
	while (i--)
		free (tab[i]);
	free (tab);
}

/*-------------------------------------------------*/
void	free_function2(int index, char **tab)
{
	int	i;

	i = index - 1;
	while (i--)
		free (tab[i]);
	free (tab);
}
