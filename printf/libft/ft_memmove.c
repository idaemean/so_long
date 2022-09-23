/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:26:35 by iczarnie          #+#    #+#             */
/*   Updated: 2021/11/23 16:26:35 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	if (dest == src || !n)
		return (dest);
	if (dest > src)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			*((unsigned char *)dest + i) = *((unsigned char *)src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)n)
		{
			*((unsigned char *)dest + i) = *((unsigned char *)src + i);
			i++;
		}
	}
	return (dest);
}
