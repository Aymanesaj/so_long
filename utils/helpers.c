/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:20:39 by asajed            #+#    #+#             */
/*   Updated: 2025/01/28 16:44:26 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free(char **strs)
{
	int	j;

	j = 0;
	while (strs[j])
	{
		free(strs[j]);
		j++;
	}
	free(strs);
	strs = NULL;
}

int	ft_len(char *map)
{
	int	i;

	i = 0;
	while (map[i] && map[i] != '\n')
		i++;
	return (i);
}

int	last_line(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i - 1);
}
