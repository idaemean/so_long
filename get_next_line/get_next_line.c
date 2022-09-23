/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 10:21:16 by iczarnie          #+#    #+#             */
/*   Updated: 2022/01/30 10:21:16 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_buffer(char *buffer)
{
	char	*new_buffer;
	int		i;
	int		b;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = (char *)malloc((ft_strlen_gnl(buffer) - i + 1) * sizeof(char));
	if (!new_buffer)
		return (NULL);
	b = i + 1;
	i = 0;
	while (buffer[b])
		new_buffer[i++] = buffer[b++];
	new_buffer[i] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*ft_line_read(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)malloc(i + 2 * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer [i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_read(int fd, char *buffer)
{
	int		read_flag;
	char	*placeholder;

	read_flag = 1;
	placeholder = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!placeholder)
		return (NULL);
	while (read_flag != 0 && !(ft_strchr_gnl(buffer, '\n')))
	{
		read_flag = read(fd, placeholder, BUFFER_SIZE);
		if (read_flag == -1)
		{
			free(placeholder);
			return (NULL);
		}
		placeholder[read_flag] = '\0';
		buffer = ft_strjoin_gnl(buffer, placeholder);
	}
	free(placeholder);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line_read(buffer);
	buffer = ft_buffer(buffer);
	return (line);
}
