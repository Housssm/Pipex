# SRCS = \
# 	Src/main.c\
# 	Src/first_step.c\
# 	Src/parsing.c\
# 	Src/pipex_utils.c\
# 	Src/heredoc.c

# OBJS = ${SRCS:.c=.o}

# NAME = pipex

# HEADER = pipex.h

# LIBFT_DIR = ./libft
# LIBFT = ${LIBFT_DIR}/libft.a

# PRINTF_DIR = ./printf
# PRINTF = ${PRINTF_DIR}/libftprintf.a

# CC = cc

# CFLAGS = -Wall -Werror -Wextra -g3

# all:     ${NAME}

# ${NAME}: ${LIBFT} ${PRINTF} ${OBJS}
# 	${CC} ${CFLAGS} ${OBJS} ${LIBFT} ${PRINTF} -o ${NAME}

# ${LIBFT}:
# 	make -C ${LIBFT_DIR}

# ${PRINTF}:
# 	make -C ${PRINTF_DIR}

# %.o: %.c ${HEADER}
# 	${CC} ${CFLAGS} -I${LIBFT_DIR} -I${PRINTF_DIR} -c $< -o $@

# clean:
# 	rm -f ${OBJS}
# 	make -C ${LIBFT_DIR} clean
# 	make -C ${PRINTF_DIR} clean

# fclean:    clean
# 	rm -f ${NAME}
# 	rm -f a.out
# 	make -C ${LIBFT_DIR} fclean
# 	make -C ${PRINTF_DIR} fclean

# re:    fclean all

# .PHONY: all clean fclean re


SRCS = \
	Src/main.c\
	Src/first_step.c\
	Src/parsing.c\
	Src/pipex_utils.c\
	Src/heredoc.c

OBJS = ${SRCS:.c=.o}

NAME = pipex

HEADER = pipex.h

LIBFT_DIR = ./libft
LIBFT = ${LIBFT_DIR}/libft.a

PRINTF_DIR = ./printf
PRINTF = ${PRINTF_DIR}/libftprintf.a

GNL_DIR = ./GNL
GNL = ${GNL_DIR}/get_next_line.a

CC = cc

CFLAGS = -Wall -Werror -Wextra -g3

all:     ${NAME}

${NAME}: ${LIBFT} ${PRINTF} ${GNL} ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${GNL} ${LIBFT} ${PRINTF} -o ${NAME}

${LIBFT}:
	make -C ${LIBFT_DIR}

${PRINTF}:
	make -C ${PRINTF_DIR}

${GNL}:
	make -C ${GNL_DIR}

%.o: %.c ${HEADER}
	${CC} ${CFLAGS} -I${LIBFT_DIR} -I${PRINTF_DIR} -I${GNL_DIR} -c $< -o $@

clean:
	rm -f ${OBJS}
	make -C ${LIBFT_DIR} clean
	make -C ${PRINTF_DIR} clean
	make -C ${GNL_DIR} clean

fclean:    clean
	rm -f ${NAME}
	rm -f a.out
	make -C ${LIBFT_DIR} fclean
	make -C ${PRINTF_DIR} fclean
	make -C ${GNL_DIR} fclean

re:    fclean all

.PHONY: all clean fclean re