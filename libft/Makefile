
SRCS	=  ft_memset.c  ft_memcpy.c ft_strlcpy.c ft_memchr.c ft_putchar_fd.c\
			 ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c\
			 ft_strnstr.c  ft_putnbr_fd.c

OBJS	= ${SRCS:.c=.o}

BONUS			=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
					ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
					ft_lstmap.c ft_lstnew.c ft_lstsize.c\

BONUS_OBJS		= ${BONUS:.c=.o}

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

NAME	= libft.a

.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

all:	${NAME}

${NAME}:	${OBJS}
					ar rc ${NAME} ${OBJS}

clean:
				${RM} ${OBJS} ${BONUS_OBJS}

fclean:		clean
					${RM} ${NAME}

re:		fclean all

bonus:			${OBJS} ${BONUS_OBJS}
				ar rcs ${NAME} ${OBJS} ${BONUS_OBJS}

.PHONY:	all clean fclean re bonus
