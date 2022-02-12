/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:06:31 by abellakr          #+#    #+#             */
/*   Updated: 2021/11/23 19:04:08 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*p1;
	char	*p2;
	size_t	i;

	p1 = (char *)dst;
	p2 = (char *)src;
	if (p1 == NULL && p2 == NULL)
		return (NULL);
	i = -1;
	if (dst > src)
		while (len--)
			p1[len] = p2[len];
	else
		while (++i < len)
			p1[i] = p2[i];
	return (p1);
}
