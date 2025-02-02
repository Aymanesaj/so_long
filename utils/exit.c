/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:30:16 by asajed            #+#    #+#             */
/*   Updated: 2025/02/01 19:01:39 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy(t_data *ptr)
{
	if (ptr->player.img)
		mlx_destroy_image(ptr->mlx, ptr->player.img);
	if (ptr->coins.img)
		mlx_destroy_image(ptr->mlx, ptr->coins.img);
	if (ptr->wall.img)
		mlx_destroy_image(ptr->mlx, ptr->wall.img);
	if (ptr->ground.img)
		mlx_destroy_image(ptr->mlx, ptr->ground.img);
	if (ptr->door.img)
		mlx_destroy_image(ptr->mlx, ptr->door.img);
	if (ptr->pac.closed)
		mlx_destroy_image(ptr->mlx, ptr->pac.closed);
	if (ptr->pac.enemy)
		mlx_destroy_image(ptr->mlx, ptr->pac.enemy);
	if (ptr->pac.open)
		mlx_destroy_image(ptr->mlx, ptr->pac.open);
	if (ptr->pac.semi)
		mlx_destroy_image(ptr->mlx, ptr->pac.semi);
}

int	clean_and_exit(t_data *ptr, int key)
{
	if (key == 1)
		ptr->status = 1;
	else
		ptr->status = 0;
	if (ptr->win)
		mlx_destroy_window(ptr->mlx, ptr->win);
	if (ptr->map)
		ft_free(ptr->map);
	if (ptr->filled_map)
		ft_free(ptr->filled_map);
	destroy(ptr);
	if (ptr->img.img)
		mlx_destroy_image(ptr->mlx, ptr->img.img);
	if (ptr->mlx)
		(mlx_destroy_display(ptr->mlx), free(ptr->mlx));
	exit(ptr->status);
}

void	print_error_exit(char *s, t_data *ptr)
{
	ft_putstr_fd("Error : ", 2);
	ft_putstr_fd(s, 2);
	ft_putchar_fd('\n', 2);
	clean_and_exit(ptr, 1);
}
