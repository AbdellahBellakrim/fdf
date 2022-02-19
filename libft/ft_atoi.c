/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:09:53 by abellakr          #+#    #+#             */
/*   Updated: 2022/02/19 13:40:26 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	char	*p;
	int		signe;
	int		k;

	p = (char *)str;
	signe = 1;
	k = 0;
	while (*p == '\t' || *p == '\n' || *p == '\v' || \
			*p == '\r' || *p == '\f' || *p == ' ')
		p++;
	if (*p == '-')
		signe = -signe;
	if (*p == '-' || *p == '+')
		p++;
	if (*p < '0' || *p > '9')
	{
		perror ("oops invalid z !");
		exit (0);
	}
	while (*p >= '0' && *p <= '9')
	{
		k = k * 10 +(*p - 48);
		p++;
	}
	return (k * signe);
}
