/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:46:40 by asajed            #+#    #+#             */
/*   Updated: 2025/02/01 17:16:00 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	draw_image_bonus(t_data *ptr, int x, int y, char c)
{
	int (width), (height);
	width = 32;
	height = 32;
	if (c == '1')
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall.img, x * width, y
			* height);
	if (c == '0' || c == 'E')
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->ground.img, x * width,
			y * height);
	if (c == 'P')
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->pac.open, x * width, y
			* height);
	if (c == 'C')
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->coins.img, x * width, y
			* height);
	if (c == 'X')
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->pac.enemy, x * width, y
			* height);
}

void	draw_map_bonus(t_data *ptr)
{
	int (i), (j);
	i = 0;
	while (ptr->map[i])
	{
		j = 0;
		while (ptr->map[i][j])
		{
			draw_image_bonus(ptr, j, i, ptr->map[i][j]);
			j++;
		}
		i++;
	}
}
