/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 22:26:42 by abellakr          #+#    #+#             */
/*   Updated: 2021/11/23 21:17:19 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	int		size;
	char	*tab;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	while (ft_strchr(set, s1[i]))
		i++;
	while (ft_strchr(set, s1[len]))
		len--;
	if (i > len)
		return (ft_strdup(""));
	len++;
	size = len - i + 1;
	tab = (char *)malloc((size) * sizeof(char));
	if (tab)
	{
		ft_strlcpy(tab, &s1[i], size);
		return (tab);
	}
	return (NULL);
}
