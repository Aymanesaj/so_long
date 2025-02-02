/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:41:07 by asajed            #+#    #+#             */
/*   Updated: 2025/02/01 18:13:30 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	invalid_char_bonus(char **map)
{
	int (i), (k);
	i = 0;
	while (map[i])
	{
		k = 0;
		while (map[i][k])
		{
			if (map[i][k] != 'P' && map[i][k] != '0' && map[i][k] != '1'
				&& map[i][k] != 'E' && map[i][k] != 'C' && map[i][k] != '\n'
				&& map[i][k] != 'X')
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}

void	check_map_if_valid_bonus(t_data *ptr)
{
	check_if_rectangular(ptr);
	check_walls(ptr, last_line(ptr->map));
	if (count_char(ptr, 'P', 1) != 1)
		print_error_exit("there is no player", ptr);
	if (count_char(ptr, 'C', 1) == 0)
		print_error_exit("no coins to collect", ptr);
	if (count_char(ptr, 'X', 1) == 0)
		print_error_exit("there is no enemy", ptr);
	if (count_char(ptr, 'E', 1) != 1)
		print_error_exit("it must be at least one exit", ptr);
	if (invalid_char_bonus(ptr->map))
		print_error_exit("invalid character", ptr);
	ptr->coin = count_char(ptr, 'C', 1);
}

void	player_position_bonus(t_data *ptr)
{
	determine_player_xy(ptr);
	flood_fill_bonus(ptr->filled_map, ptr->player.x, ptr->player.y, ptr);
	if (count_char(ptr, 'C', 2) != 0 || count_char(ptr, 'P', 2) != 0)
		print_error_exit("player can't collect all coins", ptr);
	if (count_char(ptr, 'E', 2) != 0)
		print_error_exit("player is surrounded by walls", ptr);
}

void	parsing_bonus(t_data *ptr)
{
	if (ft_strncmp(ptr->file + (ft_strlen(ptr->file) - 4), ".ber", 4))
		print_error_exit("file format isn't supported", ptr);
	ft_map(ptr, map_len(ptr));
	check_map_if_valid_bonus(ptr);
	player_position_bonus(ptr);
}
