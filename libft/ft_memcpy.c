/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:06:03 by abellakr          #+#    #+#             */
/*   Updated: 2021/11/23 15:59:30 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*p1;
	char	*p2;

	p1 = (char *)dst;
	p2 = (char *)src;
	if (p1 == NULL && p2 == NULL)
		return (NULL);
	while (n--)
	{
		*p1++ = *p2++;
	}
	return (dst);
}
