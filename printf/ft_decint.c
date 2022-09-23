/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 20:58:02 by iczarnie          #+#    #+#             */
/*   Updated: 2022/01/06 20:58:02 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long int	ft_intlen(int a)
{
	long long int	length;
	long long int	n;

	n = a;
	length = 0;
	if (n == 0)
		length = 1;
	else if (n < 0)
	{
		length++;
		n = n * -1;
	}
	while (n > 0)
	{
		length++;
		n = n / 10;
	}
	return (length);
}

int	ft_decint(int c)
{
	ft_putnbr_fd(c, 1);
	return ((int)ft_intlen(c));
}
