/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:22:53 by asajed            #+#    #+#             */
/*   Updated: 2025/01/30 16:26:23 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	initialize_mlx(t_data *ptr)
{
	ptr->mlx = mlx_init();
	if (!ptr->mlx)
		print_error_exit("failed to inizialize mlx", ptr);
	ptr->img.img = mlx_new_image(ptr->mlx, ptr->width, ptr->height);
	if (!ptr->img.img)
		print_error_exit("can't get a new img by mlx", ptr);
	ptr->img.addr = mlx_get_data_addr(ptr->img.img, &ptr->img.bits_per_pixel, &ptr->img.size_line, &ptr->img.endian);
	if (!ptr->img.addr)
		print_error_exit("can't get data address", ptr);
	ptr->player.img = mlx_xpm_file_to_image(ptr->mlx, "assets/player1.xpm", &ptr->player.width, &ptr->player.height);
	if (!ptr->player.img)
		print_error_exit("cannot open xpm file", ptr);
	ptr->wall.img = mlx_xpm_file_to_image(ptr->mlx, "assets/wall.xpm", &ptr->wall.width, &ptr->wall.height);
	if (!ptr->wall.img)
		print_error_exit("cannot open xpm file", ptr);
	ptr->ground.img = mlx_xpm_file_to_image(ptr->mlx, "assets/desert_bg.xpm", &ptr->ground.width, &ptr->ground.height);
	if (!ptr->ground.img)
		print_error_exit("cannot open xpm file", ptr);
	ptr->win = mlx_new_window(ptr->mlx, ptr->width, ptr->height, "so_long");
	if (!ptr->win)
		print_error_exit("can't open window", ptr);
}
