/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:49:23 by iczarnie          #+#    #+#             */
/*   Updated: 2021/11/24 15:49:23 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	negativity;

	result = 0;
	negativity = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
		negativity *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str) == 1)
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * negativity);
}
