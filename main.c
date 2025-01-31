/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:58:37 by asajed            #+#    #+#             */
/*   Updated: 2025/01/31 16:15:15 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_data(t_data *ptr)
{
	ft_bzero(&ptr->img, sizeof(t_image));
	ft_bzero(&ptr->player, sizeof(t_element));
	ft_bzero(&ptr->wall, sizeof(t_element));
	ft_bzero(&ptr->coins, sizeof(t_element));
	ft_bzero(&ptr->ground, sizeof(t_element));
}

int	insert_key(int key, t_data *ptr)
{
	printf("%d\n", key);
	if (key == 65307)
		clean_and_exit(ptr, 0);
	else 
		change_coorinates(ptr, key);
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
	parsing(&ptr);
	initialize_mlx(&ptr);
	draw_map(&ptr);
	mlx_key_hook(ptr.win, insert_key, &ptr);
	mlx_hook(ptr.win, 17, 0, clean_and_exit, &ptr);
	mlx_loop(ptr.mlx);
}
