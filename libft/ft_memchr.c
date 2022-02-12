/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:18:53 by abellakr          #+#    #+#             */
/*   Updated: 2021/11/10 20:24:26 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p1;
	unsigned char	d;

	p1 = (unsigned char *)s;
	d = (unsigned char)c;
	while (n--)
	{
		if (*p1 == d)
			return (p1);
		p1++;
	}
	return (0);
}
