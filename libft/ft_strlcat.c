/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:09:58 by abellakr          #+#    #+#             */
/*   Updated: 2021/11/23 16:04:07 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	int		fin;
	int		i;

	i = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstlen < dstsize)
	{
		fin = srclen + dstlen;
		while (dstsize != 0 && dstlen < dstsize - 1 && src[i])
		{
			((char *)dst)[dstlen] = src[i];
			dstlen++;
			i++;
		}
		((char *)dst)[dstlen] = 0;
	}
	else
	fin = srclen + dstsize;
	return (fin);
}
