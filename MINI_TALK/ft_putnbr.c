/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaimi <azaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:10:40 by azaimi            #+#    #+#             */
/*   Updated: 2024/12/28 21:47:39 by azaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		n = -n;
		ft_putchar('-');
		ft_putnbr(n);
	}
	else if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}
