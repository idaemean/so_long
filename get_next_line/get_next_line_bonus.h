/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next.line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 10:21:11 by iczarnie          #+#    #+#             */
/*   Updated: 2022/01/30 10:21:11 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# ifndef MAX_FD
#  define MAX_FD 1024
# endif

char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *s, int c);

char	*get_next_line(int fd);
char	*ft_read(int fd, char *buffer);
char	*ft_line_read(char *buffer);
char	*ft_buffer(char *buffer);

#endif