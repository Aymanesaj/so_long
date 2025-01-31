/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:46:40 by asajed            #+#    #+#             */
/*   Updated: 2025/01/30 16:17:21 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_image(t_data *ptr, int x , int y, char c)
{
	int (width), (height);

	width = 32;
	height = 32;
	if (c == '1')
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall.img, x  *width, y * height);
	if (c == '0')
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->ground.img, x * width, y * height);
	if (c == 'P')
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->player.img, x * width, y * height);
}

void	draw_map(t_data *ptr)
{
	int (i), (j);

	i = 0;
	while(ptr->map[i])
	{
		j = 0;
		while (ptr->map[i][j])
		{
			draw_image(ptr, j , i, ptr->map[i][j]);
			j++;
		}
		i++;
	}
}
