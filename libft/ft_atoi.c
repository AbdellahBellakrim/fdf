/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:09:53 by abellakr          #+#    #+#             */
/*   Updated: 2022/02/19 16:12:42 by abellakr         ###   ########.fr       */
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
	if (*p == '-')
	{
		signe = -signe;
		p++;
	}
	while (*p >= '0' && *p <= '9')
	{
		k = k * 10 +(*p - 48);
		p++;
	}
	return (k * signe);
}
