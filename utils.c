/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:31:10 by abellakr          #+#    #+#             */
/*   Updated: 2022/02/23 21:56:36 by abellakr         ###   ########.fr       */
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
	if (!t)
		return (NULL);
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
	n = read(fd, buff, 1);
	while (n > 0)
	{
		line[i++] = buff[0];
		line[i] = '\0';
		if (buff[0] == '\n')
			return (ft_strdup2(line));
		n = read(fd, buff, 1);
	}
	if (!line[0])
		return (NULL);
	return (ft_strdup2(line));
}

/*---------------------------------------*/
int	atoi_hexa(char *number)
{
	int	sum;

	sum = 0;
	if (number == NULL)
		return (0);
	if (ft_strncmp(number, "0x", 2) >= 0 || ft_strncmp(number, "0X", 2) >= 0)
		sum = handle_cases_atoh(sum, number);
	else
		return (ft_atoi(number));
	return (sum);
}

/*---------------------------------------*/
int	handle_cases_atoh(int sum, char *number)
{
	int	i;
	int	j;

	j = 0;
	if (ft_strlen(number) > 8)
		i = 7;
	else
		i = ft_strlen(number) - 1;
	while (i > 1)
	{
		if (number[i] >= 'A' && number[i] <= 'F')
			sum = sum + (number[i] - 55) * pow(16, j);
		if (number[i] >= 'a' && number[i] <= 'f')
			sum = sum + (number[i] - 87) * pow(16, j);
		if (number[i] >= '0' && number[i] <= '9')
			sum = sum + (number[i] - 48) * pow(16, j);
		i--;
		j++;
	}
	return (sum);
}
//0x FFFFFF