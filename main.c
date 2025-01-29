/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:58:37 by asajed            #+#    #+#             */
/*   Updated: 2025/01/28 18:58:24 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ini(void)
{
}

int	main(int ac, char **av)
{
	t_data	ptr;

	if (ac != 2)
		return (1);
	ft_bzero(&ptr, sizeof(t_data));
	ptr.file = av[1];
	parsing(&ptr);
	clean_and_exit(&ptr, 0);
}
