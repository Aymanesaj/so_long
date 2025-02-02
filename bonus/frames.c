/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:46:04 by asajed            #+#    #+#             */
/*   Updated: 2025/02/01 17:55:22 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	player_frames(t_data *ptr)
{
	if (ptr->frames <= 10000)
	{
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->pac.open,
			ptr->player.x * 32, ptr->player.y * 32);
	}
	else if (ptr->frames <= 20000)
	{
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->pac.semi,
			ptr->player.x * 32, ptr->player.y * 32);
	}
	else if (ptr->frames <= 30000)
	{
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->pac.closed,
			ptr->player.x * 32, ptr->player.y * 32);
	}
	else
	{
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->pac.open,
			ptr->player.x * 32, ptr->player.y * 32);
		ptr->frames = 0;
		return ;
	}
}
