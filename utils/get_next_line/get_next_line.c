/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:43:30 by asajed            #+#    #+#             */
/*   Updated: 2025/01/28 16:46:29 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*update(char **buffer, char *gline, int len)
{
	char	*temp;

	temp = ft_nstrjoin(gline, substr(*buffer, 0, len));
	if (!temp)
		return (NULL);
	ft_memcpy(*buffer, *buffer + len, BUFFER_SIZE - len + 1);
	return (temp);
}

int	checkline(char *gline, int bytes)
{
	int	i;

	i = 0;
	while (gline[i] != '\n' && gline[i])
		i++;
	if (gline[i] != '\n' && bytes == 0 && gline[0] != '\0')
		return (1);
	return (gline[i] == '\n');
}

int	read_and_allocate(int fd, char **buffer)
{
	if (!*buffer)
	{
		*buffer = malloc(BUFFER_SIZE + 1);
		if (!*buffer)
			return (-1);
		ft_memset(*buffer, 0, BUFFER_SIZE + 1);
	}
	if ((*buffer)[0] == '\0')
		return (read(fd, *buffer, BUFFER_SIZE));
	return (BUFFER_SIZE);
}

static char	*ft_free(char **buffer, char **gline, int fd, int bytes)
{
	if (bytes == 0 && (*gline) && (*gline)[0] != '\0')
		return ((*gline));
	if ((*gline))
		free((*gline));
	if (buffer[fd])
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*gline;
	int			bytes;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	bytes = 1;
	gline = NULL;
	while (bytes > 0)
	{
		bytes = read_and_allocate(fd, &buffer[fd]);
		if (bytes <= 0)
			break ;
		buffer[fd][bytes] = '\0';
		gline = update(&buffer[fd], gline, lenght(NULL, buffer[fd]));
		if (!gline)
			return (NULL);
		if (checkline(gline, bytes))
			return (gline);
		ft_memset(buffer[fd], 0, BUFFER_SIZE + 1);
	}
	return (ft_free(buffer, &gline, fd, bytes));
}
