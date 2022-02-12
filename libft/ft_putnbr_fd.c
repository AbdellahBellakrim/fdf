/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 04:39:54 by abellakr          #+#    #+#             */
/*   Updated: 2021/11/23 21:58:59 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	number;

	number = (long)n;
	if (number < 0)
	{
		if (number != -2147483648)
		{
			number = -number;
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(number, fd);
		}
		else
			write(fd, "-2147483648", 11);
	}
	else if (number >= 0 && number <= 9)
		ft_putchar_fd(number + 48, fd);
	else
	{
		ft_putnbr_fd((number / 10), fd);
		ft_putchar_fd((number % 10 + 48), fd);
	}
}
