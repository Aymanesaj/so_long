/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 09:01:57 by asajed            #+#    #+#             */
/*   Updated: 2025/01/28 18:38:29 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx.h"
# include "minilibx/mlx_int.h"
# include "LIBFT/libft.h"
# include "utils/get_next_line/get_next_line.h"

typedef struct s_element
{
	int			x;
	void		*img;
	int			y;
	int			pixel_x;
	int			pixel_y;
	int			height;
	int			width;
}				t_element;

typedef struct s_data
{
	int			width;
	int			height;
	int			status;
	void		*mlx;
	void		*win;
	char		**map;
	char		*file;
	char		**filled_map;
	int			coins;
	int			rows;
	int			columns;
	char		*addr;
	t_element	player;
	t_element	wall;
	t_element	ground;
	int			endian;
	int			fd;
}				t_data;

void			parsing(t_data *ptr);
void			ft_free(char **strs);
int				ft_len(char *map);
int				last_line(char **map);
void			print_error_exit(char *s, t_data *ptr);
void			clean_and_exit(t_data *ptr, int key);
void			check_map_if_valid(t_data *ptr);
void			player_position(t_data *ptr);
int				count_char(t_data *ptr, char c, int num);
#endif