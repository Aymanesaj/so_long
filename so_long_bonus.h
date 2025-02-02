/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 09:01:57 by asajed            #+#    #+#             */
/*   Updated: 2025/02/01 19:07:01 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "so_long.h"
# include <mlx.h>

void	parsing_bonus(t_data *ptr);
void	change_coordinates_bonus(t_data *ptr, int key);
void	initialize_mlx_bonus(t_data *ptr);
void	draw_map_bonus(t_data *ptr);
void	move_left(t_data *ptr);
void	move_right(t_data *ptr);
void	move_up(t_data *ptr);
void	move_down(t_data *ptr);
int		checkcoins_exit_bonus(t_data *ptr, int x, int y);
void	player_frames(t_data *ptr);
void	flood_fill_bonus(char **map, int x, int y, t_data *ptr);
void	determine_player_xy(t_data *ptr);

#endif