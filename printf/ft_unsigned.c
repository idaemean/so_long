/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:50:25 by iczarnie          #+#    #+#             */
/*   Updated: 2022/01/07 14:50:25 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlen( unsigned int a)
{
	int				length;
	unsigned int	n;

	n = a;
	length = 0;
	if (n == 0)
		length = 1;
	while (n > 0)
	{
		length++;
		n = n / 10;
	}
	return (length);
}

int	ft_unsigned(unsigned int nb)
{
	if (nb < 10)
	{
		ft_putchar_fd(nb + '0', 1);
	}
	else if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, 1);
		ft_putnbr_fd(nb % 10, 1);
	}
	return ((int)ft_intlen(nb));
}
