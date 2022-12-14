NAME		= so_long
LIBFT		= libft
LIBFT_LIB	= libft.a

MLX		= minilibx-linux
MLXFLAGS := -L minilibx-linux -lmlx -lXext -lX11 -lz -lm


SRCS		= so_long.c \
			  image.c \
			  map.c  move.c\
			  get_next_line.c \
			  get_next_line_utils.c \
			  utils.c check_pathway.c



OBJS		= $(SRCS:%.c=%.o)

LIBC		= ar rc

FLAGS		= -Wall -Wextra -Werror -g3

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		make all -C $(LIBFT)
		make all -C $(MLX)
		gcc $(OBJS) -Llibft -lft $(MLXFLAGS) -o $(NAME)

%.o			:	%.c
		gcc $(FLAGS) $(MLXFLAGS) -c -I./ -o $@ $^


clean		:
		rm -f $(OBJS)
		make clean -C $(LIBFT)
		make clean -C $(MLX)

fclean		:	clean
		rm -f $(NAME)
		rm -f $(LIBFT_LIB)
		make fclean -C $(LIBFT)

re			:	fclean all

.PHONY		:	all clean fclean re bonus