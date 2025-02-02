/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:28:51 by asajed            #+#    #+#             */
/*   Updated: 2025/02/01 19:05:22 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	move_right(t_data *ptr)
{
	if (ptr->pac.open)
		mlx_destroy_image(ptr->mlx, ptr->pac.open);
	if (ptr->pac.semi)
		mlx_destroy_image(ptr->mlx, ptr->pac.semi);
	ptr->pac.open = mlx_xpm_file_to_image(ptr->mlx, "assets/pac.xpm",
			&ptr->player.width, &ptr->player.height);
	if (!ptr->pac.open)
		print_error_exit("cannot open xpm file", ptr);
	ptr->pac.semi = mlx_xpm_file_to_image(ptr->mlx, "assets/pac_semi_right.xpm",
			&ptr->player.width, &ptr->player.height);
	if (!ptr->pac.semi)
		print_error_exit("cannot open xpm file", ptr);
	ptr->player.x += 1;
}

void	move_left(t_data *ptr)
{
	if (ptr->pac.open)
		mlx_destroy_image(ptr->mlx, ptr->pac.open);
	if (ptr->pac.semi)
		mlx_destroy_image(ptr->mlx, ptr->pac.semi);
	ptr->pac.open = mlx_xpm_file_to_image(ptr->mlx, "assets/pac_open_left.xpm",
			&ptr->player.width, &ptr->player.height);
	if (!ptr->pac.open)
		print_error_exit("cannot open xpm file", ptr);
	ptr->pac.semi = mlx_xpm_file_to_image(ptr->mlx, "assets/pac_semi_left.xpm",
			&ptr->player.width, &ptr->player.height);
	if (!ptr->pac.semi)
		print_error_exit("cannot open xpm file", ptr);
	ptr->player.x -= 1;
}

void	move_up(t_data *ptr)
{
	if (ptr->pac.open)
		mlx_destroy_image(ptr->mlx, ptr->pac.open);
	if (ptr->pac.semi)
		mlx_destroy_image(ptr->mlx, ptr->pac.semi);
	ptr->pac.open = mlx_xpm_file_to_image(ptr->mlx, "assets/pac_open_up.xpm",
			&ptr->player.width, &ptr->player.height);
	if (!ptr->pac.open)
		print_error_exit("cannot open xpm file", ptr);
	ptr->pac.semi = mlx_xpm_file_to_image(ptr->mlx, "assets/pac_semi_up.xpm",
			&ptr->player.width, &ptr->player.height);
	if (!ptr->pac.semi)
		print_error_exit("cannot open xpm file", ptr);
	ptr->player.y -= 1;
}

void	move_down(t_data *ptr)
{
	if (ptr->pac.open)
		mlx_destroy_image(ptr->mlx, ptr->pac.open);
	if (ptr->pac.semi)
		mlx_destroy_image(ptr->mlx, ptr->pac.semi);
	ptr->pac.open = mlx_xpm_file_to_image(ptr->mlx, "assets/pac_open_down.xpm",
			&ptr->player.width, &ptr->player.height);
	if (!ptr->pac.open)
		print_error_exit("cannot open xpm file", ptr);
	ptr->pac.semi = mlx_xpm_file_to_image(ptr->mlx, "assets/pac_semi_down.xpm",
			&ptr->player.width, &ptr->player.height);
	if (!ptr->pac.semi)
		print_error_exit("cannot open xpm file", ptr);
	ptr->player.y += 1;
}
