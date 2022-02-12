/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:08:05 by abellakr          #+#    #+#             */
/*   Updated: 2021/11/16 23:31:33 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	unsigned int	i;
	size_t			len;

	if (!s || !(f))
		return (NULL);
	len = ft_strlen(s) + 1;
	ptr = (char *)malloc(len);
	i = 0;
	if (!ptr)
		return (NULL);
	if (s[0] == 0)
		ptr[i] = 0;
	while (s[i] && i < len)
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
