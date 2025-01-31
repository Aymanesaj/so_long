/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 09:23:56 by asajed            #+#    #+#             */
/*   Updated: 2025/01/31 10:13:20 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_char(t_data *ptr, char c, int num)
{
	char	**map;

	int(i), (j), (count);
	i = 1;
	j = 0;
	count = 0;
	if (num == 1)
		map = ptr->map;
	else
		map = ptr->filled_map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	check_if_rectangular(t_data *ptr)
{
	char	**map;

	int (i), (j);
	i = 0;
	j = -1;
	map = ptr->map;
	while (map[i] && map[i][0] != '\n')
	{
		if (j != -1 && j != ft_len(map[i]))
			print_error_exit("map must be rectangular", ptr);
		j = ft_len(map[i]);
		i++;
	}
	ptr->rows = j;
	ptr->columns = last_line(map);
	ptr->width = 32 * j;
	ptr->height = 32 * ptr->columns + 32 ;
	if (ptr->rows > 60 || ptr->columns > 32)
		print_error_exit("map is too large", ptr);
}

void	check_walls(t_data *ptr, int j)
{
	int (i), (k);
	i = 0;
	k = ft_strlen(ptr->map[0]) - 2;
	while (ptr->map[i])
	{
		if (ptr->map[i][0] != '1' || ptr->map[i][k] != '1')
			print_error_exit("map must be surrounded by walls", ptr);
		i++;
	}
	i = 0;
	while (ptr->map[0][i] && ptr->map[0][i] != '\n')
	{
		if (ptr->map[0][i] != '1')
			print_error_exit("map must be surrounded by walls", ptr);
		i++;
	}
	i = 0;
	while (ptr->map[j][i] && ptr->map[j][i] != '\n')
	{
		if (ptr->map[j][i] != '1')
			print_error_exit("map must be surrounded by walls", ptr);
		i++;
	}
}

int	invalid_char(char **map)
{
	int (i), (k);
	i = 0;
	while (map[i])
	{
		k = 0;
		while (map[i][k])
		{
			if (map[i][k] != 'P' && map[i][k] != '0' && map[i][k] != '1'
				&& map[i][k] != 'E' && map[i][k] != 'C' && map[i][k] != '\n')
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}

void	check_map_if_valid(t_data *ptr)
{
	check_if_rectangular(ptr);
	check_walls(ptr, last_line(ptr->map));
	if (count_char(ptr, 'P', 1) != 1)
		print_error_exit("there is no player", ptr);
	if (count_char(ptr, 'C', 1) == 0)
		print_error_exit("no coins to collect", ptr);
	if (count_char(ptr, 'E', 1) != 1)
		print_error_exit("it must be at least one exit", ptr);
	if (invalid_char(ptr->map))
		print_error_exit("invalid character", ptr);
}
