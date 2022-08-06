/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_leaks_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:27:22 by abellakr          #+#    #+#             */
/*   Updated: 2022/02/26 14:38:37 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

/*-------------------------------------------------*/
void	free_function_bonus(int index, t_map **tab)
{
	int	i;

	i = index - 1;
	while (i--)
		free (tab[i]);
	free (tab);
}

/*-------------------------------------------------*/
void	free_function2_bonus(int index, char **tab)
{
	int	i;

	i = index;
	while (i--)
		free (tab[i]);
	free (tab);
}
