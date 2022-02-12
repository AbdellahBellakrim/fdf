/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 12:08:14 by abellakr          #+#    #+#             */
/*   Updated: 2021/11/19 17:04:13 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*p1;
	char	*p2;
	size_t	sizesrc;

	p1 = (char *)dst;
	p2 = (char *)src;
	sizesrc = ft_strlen(p2);
	if (sizesrc + 1 < dstsize)
	{
		ft_memcpy (p1, p2, sizesrc);
		p1[sizesrc] = 0;
	}
	else if (dstsize != 0)
	{
		ft_memcpy (p1, p2, dstsize - 1);
		p1[dstsize - 1] = 0;
	}
	return (sizesrc);
}
