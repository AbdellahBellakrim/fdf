/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 02:07:33 by abellakr          #+#    #+#             */
/*   Updated: 2021/11/23 21:43:59 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_n(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	if (n == 0)
		i = 1;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*tab;
	int		len;
	long	number;

	number = (long)n;
	len = len_n(n);
	tab = (char *)malloc((len + 1) * sizeof(char));
	if (!tab)
		return (0);
	tab[len] = 0;
	if (number == 0)
		tab[0] = '0';
	if (number < 0)
	{
		number = -number;
		tab[0] = '-';
	}
	while (len-- && number > 0)
	{
		tab[len] = number % 10 + 48;
		number = number / 10;
	}
	return (tab);
}
