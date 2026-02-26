SRCS = get_next_line.c \
	get_next_line_utils.c

OBJS = ${SRCS:.c=.o}

NAME = get_next_line.a

HEADER = get_next_line.h

LIBFT_DIR = ../libft
LIBFT = ${LIBFT_DIR}/libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra -g3

all: ${NAME}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

%.o: %.c ${HEADER}
	${CC} ${CFLAGS} -I${LIBFT_DIR} -c $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re

.SILENT :