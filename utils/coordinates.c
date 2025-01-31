/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 08:46:03 by asajed            #+#    #+#             */
/*   Updated: 2025/01/31 10:06:34 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdio.h>
#include <stdlib.h>

char	**duplicate_map(t_data *ptr)
{
	char	**map_dup;
	int		i;

	i = 0;
	map_dup = malloc(sizeof(char **) * (ptr->rows + 1));
	while (ptr->map[i])
	{
		map_dup[i] = ft_strdup(ptr->map[i]);
		i++;
	}
	map_dup[i] = NULL;
	return (map_dup);
}

void	flood_fill(char **map, int x, int y, t_data *ptr)
{
	if (x < 0 || y < 0 || x >= ptr->rows || y >= ptr->columns)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	// if (map[y][x] == 'E' && count_char(ptr, 'C', 2) != 0)
	// 	return ;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, ptr);
	flood_fill(map, x - 1, y, ptr);
	flood_fill(map, x, y + 1, ptr);
	flood_fill(map, x, y - 1, ptr);
}

void	determine_player_xy(t_data *ptr)
{
	int(x), (y);
	y = 0;
	while (ptr->map[y])
	{
		x = 0;
		while (ptr->map[y][x])
		{
			if (ptr->map[y][x] == 'P')
			{
				ptr->player.x = x;
				ptr->player.y = y;
				ptr->filled_map = duplicate_map(ptr);
				return ;
			}
			x++;
		}
		y++;
	}
	print_error_exit("map is invalid", ptr);
}

void	player_position(t_data *ptr)
{
	determine_player_xy(ptr);
	flood_fill(ptr->filled_map, ptr->player.x, ptr->player.y, ptr);
	if (count_char(ptr, 'C', 2) != 0 || count_char(ptr, 'P', 2) != 0)
		print_error_exit("player can't collect all coins", ptr);
	if (count_char(ptr, 'E', 2) != 0)
		print_error_exit("player is surrounded by walls", ptr);
}
