/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:58:37 by asajed            #+#    #+#             */
/*   Updated: 2025/01/28 17:47:13 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac , char **av)
{
    t_data	*ptr;

	if (ac != 2)
		return (1);
	ptr = malloc(sizeof(t_data));
    if (!ptr)
		perror("malloc failed");
    ft_bzero((t_data *)ptr, sizeof(t_data *));
	ptr->map = NULL;
	ptr->file = av[1];
    parsing(ptr);
}
