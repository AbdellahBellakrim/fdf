/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:09:45 by abellakr          #+#    #+#             */
/*   Updated: 2021/11/24 14:02:51 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_conter(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			words++;
		while (s[i] != c && s[i])
			i++;
	}
	return (words);
}

static char	*word_alloc(char const *s, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	ft_strlcpy (word, s, i + 1);
	return (word);
}

static void	free_func(char **tab, int size)
{
	while (size != -1)
	{
		free (tab[size]);
			size--;
	}
	free (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		size;
	int		j;

	if (s)
	{
		j = 0;
		size = word_conter(s, c);
		tab = (char **)malloc(sizeof(char *) * (size + 1));
		if (!tab)
			return (NULL);
		while (j < size)
		{
			while (*s == c)
				s++;
			tab[j] = word_alloc(s, c);
			if (!tab[j])
				free_func(tab, j - 1);
			s = s + ft_strlen(tab[j]);
			j++;
		}
		tab[j] = NULL;
		return (tab);
	}
	return (NULL);
}
