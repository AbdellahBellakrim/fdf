/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:39:36 by abellakr          #+#    #+#             */
/*   Updated: 2021/11/23 18:29:10 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p1;
	char	*p2;
	char	*p3;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	p1 = (char *)malloc(i * sizeof(char) + 1);
	p2 = (char *)s1;
	p3 = p1;
	if (!p1)
		return (NULL);
	while (*p2)
		*p1++ = *p2++;
	*p1 = 0;
	return (p3);
}
