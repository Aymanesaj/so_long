/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_mlx_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:22:53 by asajed            #+#    #+#             */
/*   Updated: 2025/02/01 19:06:57 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	init_player(t_data *ptr)
{
	ptr->pac.open = mlx_xpm_file_to_image(ptr->mlx, "assets/pac.xpm",
			&ptr->player.width, &ptr->player.height);
	if (!ptr->pac.open)
		print_error_exit("cannot open xpm file", ptr);
	ptr->pac.semi = mlx_xpm_file_to_image(ptr->mlx, "assets/pac_semi_right.xpm",
			&ptr->player.width, &ptr->player.height);
	if (!ptr->pac.semi)
		print_error_exit("cannot open xpm file", ptr);
	ptr->pac.closed = mlx_xpm_file_to_image(ptr->mlx, "assets/pac_closed.xpm",
			&ptr->player.width, &ptr->player.height);
	if (!ptr->pac.closed)
		print_error_exit("cannot open xpm file", ptr);
	ptr->pac.enemy = mlx_xpm_file_to_image(ptr->mlx, "assets/ghost_down1.xpm",
			&ptr->pac.e_x, &ptr->pac.e_y);
	if (!ptr->pac.enemy)
		print_error_exit("cannot open xpm file", ptr);
}

void	initialize_mlx_bonus(t_data *ptr)
{
	ptr->mlx = mlx_init();
	if (!ptr->mlx)
		print_error_exit("failed to inizialize mlx", ptr);
	ptr->coins.img = mlx_xpm_file_to_image(ptr->mlx, "assets/coins.xpm",
			&ptr->coins.width, &ptr->coins.height);
	if (!ptr->coins.img)
		print_error_exit("cannot open xpm file", ptr);
	ptr->wall.img = mlx_xpm_file_to_image(ptr->mlx, "assets/wall.xpm",
			&ptr->wall.width, &ptr->wall.height);
	if (!ptr->wall.img)
		print_error_exit("cannot open xpm file", ptr);
	ptr->ground.img = mlx_xpm_file_to_image(ptr->mlx, "assets/ground.xpm",
			&ptr->ground.width, &ptr->ground.height);
	if (!ptr->ground.img)
		print_error_exit("cannot open xpm file", ptr);
	ptr->door.img = mlx_xpm_file_to_image(ptr->mlx, "assets/portal.xpm",
			&ptr->door.width, &ptr->door.height);
	if (!ptr->door.img)
		print_error_exit("cannot open xpm file", ptr);
	init_player(ptr);
	ptr->win = mlx_new_window(ptr->mlx, ptr->width, ptr->height, "so_long");
	if (!ptr->win)
		print_error_exit("can't open window", ptr);
}
