/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:48:34 by abellakr          #+#    #+#             */
/*   Updated: 2021/11/23 16:29:42 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int			i;
	int			j;
	size_t		hach;

	i = 0;
	if (((char *)needle)[0] == 0)
		return ((char *)haystack);
	while (((char *)haystack)[i] && len)
	{
		j = 0;
		if (((char *)needle)[j] == ((char *)haystack)[i])
		{
			hach = len;
			while (((char *)needle)[j] == ((char *)haystack)[i + j] && hach)
			{
				if (((char *)needle)[j + 1] == 0)
					return (&((char *)haystack)[i]);
				j++;
				hach--;
			}
		}
		len--;
		i++;
	}
	return (0);
}
