/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lesaks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:27:22 by abellakr          #+#    #+#             */
/*   Updated: 2022/02/21 10:28:06 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*-----------------------------------------------*/
void	free_function(int index, map **tab)
{
	int	i;

	i = index - 1;
	while (i--)
		free (tab[i]);
	free (tab);
}

/*-------------------------------------------------*/
void	free_function2(int index, char **tab)
{
	int	i;

	i = index - 1;
	while (i--)
		free (tab[i]);
	free (tab);
}