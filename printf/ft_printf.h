/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:20:50 by iczarnie          #+#    #+#             */
/*   Updated: 2022/01/05 13:20:50 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int	ft_char(char c);
int	ft_printf(const	char *format, ...);
int	ft_str(char *str);
int	ft_decint(int c);
int	ft_unsigned(unsigned int nb);
int	ft_hex(unsigned int x, char c);
int	ft_pointer(void *p);

#endif