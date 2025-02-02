/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:26:18 by asajed            #+#    #+#             */
/*   Updated: 2025/02/01 19:14:16 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	initialize_data(t_data *ptr)
{
	ft_bzero(&ptr->img, sizeof(t_image));
	ft_bzero(&ptr->player, sizeof(t_element));
	ft_bzero(&ptr->wall, sizeof(t_element));
	ft_bzero(&ptr->coins, sizeof(t_element));
	ft_bzero(&ptr->ground, sizeof(t_element));
	ft_bzero(&ptr->door, sizeof(t_element));
	ft_bzero(&ptr->pac, sizeof(t_player));
}

int	insert_key_bonus(int key, t_data *ptr)
{
	if (key == 65307)
		clean_and_exit(ptr, 0);
	else
		change_coordinates_bonus(ptr, key);
	return (0);
}

int	frames_change(t_data *ptr)
{
	player_frames(ptr);
	ptr->frames++;
	return (0);
}

int	main(int ac, char **av)
{
	t_data	ptr;

	if (ac != 2)
		exit (1);
	ft_bzero(&ptr, sizeof(t_data));
	initialize_data(&ptr);
	ptr.file = av[1];
	parsing_bonus(&ptr);
	initialize_mlx_bonus(&ptr);
	draw_map_bonus(&ptr);
	mlx_key_hook(ptr.win, insert_key_bonus, &ptr);
	mlx_hook(ptr.win, 17, 0, clean_and_exit, &ptr);
	mlx_loop_hook(ptr.mlx, frames_change, &ptr);
	mlx_loop(ptr.mlx);
}
