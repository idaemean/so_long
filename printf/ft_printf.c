/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:51:23 by iczarnie          #+#    #+#             */
/*   Updated: 2022/01/05 17:51:23 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conversion(const char *p, va_list args)
{
	if (*p == 'c')
		return (ft_char(va_arg(args, int)));
	if (*p == 's')
		return (ft_str(va_arg(args, char *)));
	if (*p == 'd' || *p == 'i')
		return (ft_decint(va_arg(args, int)));
	if (*p == 'u')
		return (ft_unsigned(va_arg(args, unsigned int)));
	if (*p == 'p')
		return (ft_pointer(va_arg(args, void *)));
	if (*p == 'x')
		return (ft_hex(va_arg(args, unsigned int), 'x'));
	if (*p == 'X')
		return (ft_hex(va_arg(args, unsigned int), 'X'));
	if (*p == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const	char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i += 1;
			count += ft_conversion(&format[i], args);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
