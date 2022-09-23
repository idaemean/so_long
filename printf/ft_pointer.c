/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:25:02 by iczarnie          #+#    #+#             */
/*   Updated: 2022/01/10 12:25:02 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_convert(unsigned long x)
{
	if (x <= 9)
		ft_putchar_fd (x + 48, 1);
	else if (x >= 10)
		ft_putchar_fd (x + 87, 1);
}

static int	ft_p_hex(unsigned long x)
{
	int	i;

	i = 1;
	if (x >= 16)
		ft_p_hex(x / 16);
	ft_convert(x % 16);
	while (x >= 16)
	{
		x = x / 16;
		i += 1;
	}
	return (i);
}

int	ft_pointer(void *p)
{
	unsigned long	address;

	address = (unsigned long)p;
	ft_putstr_fd("0x", 1);
	return (2 + ft_p_hex(address));
}
