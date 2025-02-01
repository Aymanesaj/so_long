/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 09:01:57 by asajed            #+#    #+#             */
/*   Updated: 2025/02/01 10:15:46 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "LIBFT/libft.h"
// # include "minilibx/mlx.h"
// # include "minilibx/mlx_int.h"
# include "utils/get_next_line/get_next_line.h"

typedef struct s_element
{
	int			x;
	void		*img;
	int			y;
	int			height;
	int			width;
}				t_element;

typedef struct s_image
{
	int			width;
	int			height;
	void		*img;
	char		*addr;
	int			endian;
	int			bits_per_pixel;
	int			size_line;
}				t_image;

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
	int			rows;
	int			columns;
	t_element	coins;
	t_element	player;
	t_element	wall;
	t_element	ground;
	t_element	door;
	t_image		img;
	int			fd;
	int			moves;
	int			coin;
}				t_data;

void			change_coordinates(t_data *ptr, int key);
void			parsing(t_data *ptr);
void			ft_free(char **strs);
int				ft_len(char *map);
int				last_line(char **map);
void			print_error_exit(char *s, t_data *ptr);
void			check_map_if_valid(t_data *ptr);
void			player_position(t_data *ptr);
int				count_char(t_data *ptr, char c, int num);
int				clean_and_exit(t_data *ptr, int key);
void			initialize_mlx(t_data *ptr);
void			draw_map(t_data *ptr);

#endif