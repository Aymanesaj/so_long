/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:06:33 by asajed            #+#    #+#             */
/*   Updated: 2025/02/02 10:18:41 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	free_static(char *line, int fd)
{
	int	i;

	i = 0;
	while (line)
	{
		if (*line != '\n')
			i = -1;
		free(line);
		line = get_next_line(fd);
	}
	return (i);
}

int	map_len(t_data *ptr)
{
	char	*line;
	int		i;

	i = 1;
	ptr->fd = open(ptr->file, O_RDONLY);
	if (ptr->fd == -1)
		print_error_exit("failed to open file", ptr);
	line = get_next_line(ptr->fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(ptr->fd);
	}
	close(ptr->fd);
	return (i);
}

void	empty_map(t_data *ptr)
{
	(free(ptr->map));
	ptr->map = NULL;
	(close(ptr->fd), print_error_exit("empty map", ptr));
}

void	ft_map(t_data *ptr, int maplen)
{
	char	*line;
	int		i;

	i = 0;
	ptr->fd = open(ptr->file, O_RDONLY);
	if (ptr->fd == -1)
		print_error_exit("failed to open file", ptr);
	ptr->map = (char **)malloc(sizeof(char *) * maplen + 1);
	if (!ptr->map)
		(close(ptr->fd), print_error_exit("failed to allocate", ptr));
	line = get_next_line(ptr->fd);
	if (!line)
		empty_map(ptr);
	while (line && line[0] != '\n')
	{
		ptr->map[i] = ft_strdup(line);
		(free(line), i++);
		line = get_next_line(ptr->fd);
	}
	ptr->map[i] = NULL;
	if (line)
		(free_static(line, ptr->fd), close(ptr->fd),
			print_error_exit("invalid map", ptr));
	close(ptr->fd);
}

void	parsing(t_data *ptr)
{
	int (i);
	i = 0;
	if (ft_strncmp(ptr->file + (ft_strlen(ptr->file) - 4), ".ber", 4))
		print_error_exit("file format isn't supported", ptr);
	if (!ft_strchr(ptr->file, '/'))
	{
		if (!ptr->file[4])
			print_error_exit("extention is not allowed", ptr);
	}
	else
	{
		while (ptr->file[i] && ptr->file[i] != '/')
			i++;
		if (ptr->file[i] == '/')
			i++;
		if (!ft_strncmp(ptr->file + i, ".ber", 4))
			print_error_exit("extention is not allowed", ptr);
	}
	ft_map(ptr, map_len(ptr));
	check_map_if_valid(ptr);
	player_position(ptr);
}
