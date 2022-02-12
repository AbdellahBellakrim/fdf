/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 20:45:00 by abellakr          #+#    #+#             */
/*   Updated: 2021/11/16 05:09:43 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	tofind;
	char	*str;

	tofind = (char )c;
	str = (char *)s;
	i = ft_strlen(str);
	if (tofind == 0)
		return (str + i);
	while (i--)
		if (str[i] == tofind)
			return (str + i);
	return (0);
}
