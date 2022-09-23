/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:22:04 by iczarnie          #+#    #+#             */
/*   Updated: 2022/01/07 15:22:04 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_convert(unsigned int x, char c)
{
	if (x <= 9)
		ft_putchar_fd (x + 48, 1);
	else if (c == 'x' && x >= 10)
		ft_putchar_fd (x + 87, 1);
	else if (c == 'X' && x >= 10)
		ft_putchar_fd (x + 55, 1);
}

int	ft_hex(unsigned int x, char c)
{
	int	i;

	i = 1;
	if (x >= 16)
		ft_hex(x / 16, c);
	ft_convert(x % 16, c);
	while (x >= 16)
	{
		x = x / 16;
		i += 1;
	}
	return (i);
}
