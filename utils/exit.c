/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:30:16 by asajed            #+#    #+#             */
/*   Updated: 2025/01/28 18:32:10 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    clean_and_exit(t_data *ptr, int key)
{
	int status;

	if (key == 1)
		ptr->status = 1;
	else
		ptr->status = 0;
	status = ptr->status;
	if (ptr->map)
		ft_free(ptr->map);
	if (ptr)
		free(ptr);
	exit(status);
}

void    print_error_exit(char *s, t_data *ptr)
{
    ft_putstr_fd("Error : ", 2);
    ft_putstr_fd(s, 2);
	ft_putchar_fd('\n', 1);
    clean_and_exit(ptr, 1);
}


