SRCS = \
	main.c 

OBJS = ${SRCS:.c=.o}

NAME = pipex

HEADER = pipex.h

LIBFT_DIR = ./libft
LIBFT = ${LIBFT_DIR}/libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra -g3

all:     ${NAME}

${NAME}: ${LIBFT} ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME}

${LIBFT}:				
	make -C ${LIBFT_DIR}

%.o: %.c ${HEADER}
	${CC} ${CFLAGS} -I${LIBFT_DIR} -c $< -o $@

clean:    
	rm -f ${OBJS}
	make -C ${LIBFT_DIR} clean

fclean:    clean;
	rm -f ${NAME}
	rm -f a.out
	make -C ${LIBFT_DIR} fclean

re:    fclean all

.PHONY: all clean fclean re