/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:08:21 by asajed            #+#    #+#             */
/*   Updated: 2025/01/31 16:28:18 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_player(t_data *ptr)
{
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->player.img, ptr->player.x * 32, ptr->player.y * 32);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->ground.img, ptr->ground.x * 32, ptr->ground.y * 32);
}
void	change_coorinates(t_data *ptr, int key)
{
	if (key == 65363)
	{
		if (ptr->map[ptr->player.y][ptr->player.x + 1] == '1')
			return ;
		ptr->ground.x = ptr->player.x;
		ptr->player.x += 1;
		ptr->ground.y = ptr->player.y;
	}
	if (key == 65361)
	{
		if (ptr->map[ptr->player.y][ptr->player.x - 1] == '1')
			return ;
		ptr->ground.x = ptr->player.x;
		ptr->player.x -= 1;
		ptr->ground.y = ptr->player.y;
	}
	if (key == 65362)
	{
		if (ptr->map[ptr->player.y + 1][ptr->player.x] == '1')
			return ;
		ptr->ground.x = ptr->player.x;
		ptr->ground.y = ptr->player.y;
		ptr->player.y -= 1;
	}
	if (key == 65364)
	{
		if (ptr->map[ptr->player.y + 1][ptr->player.x] == '1')
			return ;
		ptr->ground.x = ptr->player.x;
		ptr->ground.y = ptr->player.y;
		ptr->player.y += 1;
	}
	move_player(ptr);
}
