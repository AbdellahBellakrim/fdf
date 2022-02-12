/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:08:49 by abellakr          #+#    #+#             */
/*   Updated: 2021/12/09 00:29:14 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*tab;

	tab = (unsigned char *)str;
	while (n--)
		*tab++ = (unsigned char)c;
	return (str);
}
