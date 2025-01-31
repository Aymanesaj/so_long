SRCS = main.c utils/get_next_line/get_next_line.c \
utils/get_next_line/get_next_line_utils.c  utils/parsing.c\
utils/exit.c utils/helpers.c utils/valid.c utils/coordinates.c\
utils/initialize_mlx.c utils/draw_map.c utils/move_player.c


CC = cc #-fsanitize=address -g
CFLAGS = -Wall -Wextra -Werror
MLX_LIB = -lmlx -lX11 -lXext -lm
OBJS = $(SRCS:.c=.o)
LIBFT = LIBFT/libft.a
NAME = so_long

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(LIBFT) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
