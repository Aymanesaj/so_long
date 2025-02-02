/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:08:21 by asajed            #+#    #+#             */
/*   Updated: 2025/02/01 19:16:59 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	move_player_bonus(t_data *ptr)
{
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->pac.open, ptr->player.x
		* 32, ptr->player.y * 32);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->ground.img, ptr->ground.x
		* 32, ptr->ground.y * 32);
	ft_putstr_fd("moves : ", 1);
	ft_putnbr_fd(ptr->moves, 1);
	ft_putstr_fd("\n", 1);
	if (!ptr->coin)
		check_door(ptr);
}

void	flood_fill_bonus(char **map, int x, int y, t_data *ptr)
{
	if (x < 0 || y < 0 || x >= ptr->rows || y >= ptr->columns)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V' || map[y][x] == 'X')
		return ;
	map[y][x] = 'V';
	flood_fill_bonus(map, x + 1, y, ptr);
	flood_fill_bonus(map, x - 1, y, ptr);
	flood_fill_bonus(map, x, y + 1, ptr);
	flood_fill_bonus(map, x, y - 1, ptr);
}

int	checkcoins_exit_bonus(t_data *ptr, int x, int y)
{
	if (ptr->map[y][x] == '1')
		return (1);
	if (ptr->map[y][x] == 'X')
	{
		(ft_putstr_fd(":::::{ you lost }::::", 1), clean_and_exit(ptr, 0));
	}
	if (ptr->map[y][x] == 'C')
	{
		ptr->coin--;
		ptr->map[y][x] = '0';
	}
	if (ptr->map[y][x] == 'E' && ptr->coin == -1)
		(ft_putstr_fd(":::::::::{ you won }:::::::::\n", 1), clean_and_exit(ptr,
				0));
	return (0);
}

void	change_coordinates_bonus(t_data *ptr, int key)
{
	char	*num;

	ptr->ground.x = ptr->player.x;
	ptr->ground.y = ptr->player.y;
	if (key == 65363 && !(checkcoins_exit_bonus(ptr, ptr->player.x + 1,
				ptr->player.y)))
		move_right(ptr);
	else if (key == 65361 && !(checkcoins_exit_bonus(ptr, ptr->player.x - 1,
				ptr->player.y)))
		move_left(ptr);
	else if (key == 65362 && !(checkcoins_exit_bonus(ptr, ptr->player.x,
				ptr->player.y - 1)))
		move_up(ptr);
	else if (key == 65364 && !(checkcoins_exit_bonus(ptr, ptr->player.x,
				ptr->player.y + 1)))
		move_down(ptr);
	else
		return ;
	ptr->moves++;
	move_player_bonus(ptr);
	num = ft_itoa(ptr->moves);
	// mlx_string_put(ptr->mlx, ptr->win, 20, 32, 0xFF0000, "MOVES : ");
	mlx_string_put(ptr->mlx, ptr->win, 20, 132, 0xFF0000, num);
	free(num);
}
