SRCS = main.c utils/get_next_line/get_next_line.c \
utils/get_next_line/get_next_line_utils.c  utils/parsing.c\
utils/exit.c utils/helpers.c utils/valid.c utils/coordinates.c\
utils/initialize_mlx.c utils/draw_map.c utils/move_player.c

SRCS_BNS = main_bonus.c utils/get_next_line/get_next_line.c \
utils/get_next_line/get_next_line_utils.c  bonus/parsing_bonus.c\
utils/parsing.c utils/exit.c utils/helpers.c utils/valid.c \
utils/coordinates.c utils/initialize_mlx.c utils/draw_map.c \
utils/move_player.c bonus/initialize_mlx_bonus.c bonus/move_player_bonus.c\
bonus/draw_map_bonus.c bonus/directions.c bonus/frames.c \

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_LIB = -lmlx -lX11 -lXext -lm
OBJS = $(SRCS:.c=.o)
OBJS_BNS = $(SRCS_BNS:.c=.o)
LIBFT = LIBFT/libft.a
NAME = so_long
BONUS = so_long_bonus

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
	$(MAKE) -C LIBFT

bonus : $(BONUS)

$(BONUS) : $(OBJS_BNS)
	$(CC) $(CFLAGS) $(OBJS_BNS) $(MLX_LIB) $(LIBFT) -o $(BONUS)


clean:
	rm -f $(OBJS) $(OBJS_BNS)
	$(MAKE) -C LIBFT clean

fclean: clean
	rm -f $(NAME) $(BONUS)
	$(MAKE) -C LIBFT fclean

re: fclean all
