/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:08:21 by asajed            #+#    #+#             */
/*   Updated: 2025/02/27 14:23:59 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	checkcoins_exit(t_data *ptr, int x, int y)
{
	if (ptr->map[y][x] == '1')
		return (1);
	if (ptr->map[y][x] == 'C')
	{
		ptr->coin--;
		ptr->map[y][x] = '0';
	}
	if (ptr->map[y][x] == 'E' && ptr->coin == -1)
		(ft_putstr_fd("::::::::{ you won }::::::::\n", 1), clean_and_exit(ptr,
				0));
	return (0);
}

void	check_door(t_data *ptr)
{
	int (y), (x);
	y = 0;
	while (ptr->map[y])
	{
		x = 0;
		while (ptr->map[y][x])
		{
			if (ptr->map[y][x] == 'E')
			{
				mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->door.img, x
					* 32, y * 32);
				ptr->coin = -1;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	move_player(t_data *ptr)
{
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->player.img, ptr->player.x
		* 32, ptr->player.y * 32);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->ground.img, ptr->ground.x
		* 32, ptr->ground.y * 32);
	ft_putstr_fd("moves : ", 1);
	ft_putnbr_fd(ptr->moves, 1);
	ft_putstr_fd("\r", 1);
	if (!ptr->coin)
		check_door(ptr);
}

void	change_coordinates(t_data *ptr, int key)
{
	ptr->ground.x = ptr->player.x;
	ptr->ground.y = ptr->player.y;
	if (key == 65363 && !(checkcoins_exit(ptr, ptr->player.x + 1,
				ptr->player.y)))
		ptr->player.x += 1;
	else if (key == 65361 && !(checkcoins_exit(ptr, ptr->player.x - 1,
				ptr->player.y)))
		ptr->player.x -= 1;
	else if (key == 65362 && !(checkcoins_exit(ptr, ptr->player.x,
				ptr->player.y - 1)))
		ptr->player.y -= 1;
	else if (key == 65364 && !(checkcoins_exit(ptr, ptr->player.x,
				ptr->player.y + 1)))
		ptr->player.y += 1;
	else
		return ;
	ptr->moves++;
	move_player(ptr);
}
