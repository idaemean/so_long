/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:04:08 by iczarnie          #+#    #+#             */
/*   Updated: 2021/11/30 13:04:08 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static char	*ft_negative(long long int a, char *str, unsigned int len)
{
	str[0] = '-';
	a = -a;
	while (len-- > 1)
	{
		str[len] = a % 10 + '0';
		a /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	len;
	long long int	a;

	len = ft_intlen(n);
	a = n;
	str = ft_calloc(len + 1, sizeof(*str));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = 0 + '0';
	else if (n < 0)
	{
		str = ft_negative(a, str, len);
	}
	else if (n > 0)
	{
		while (len-- > 0)
		{
			str[len] = n % 10 + '0';
			n /= 10;
		}
	}
	return (str);
}
