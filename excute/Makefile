NAME		= cub3D
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -O2
SRCS		= srcs/main.c srcs/event.c srcs/move.c srcs/raycast.c srcs/render.c
OBJS		= $(SRCS:.c=.o)
LIBFT		= Libft/libft.a
MLX			= minilibx-linux/libmlx.a
MLX_FLAGS	= -L minilibx-linux -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C Libft

$(MLX):
	$(MAKE) -C minilibx-linux

%.o: %.c
	$(CC) $(CFLAGS) -I . -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C Libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C Libft fclean

re: fclean all

.PHONY: all clean fclean re
