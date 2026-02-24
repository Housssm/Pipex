RED = \033[31m
GREEN = \033[32m
CYAN = \033[36m
RESET = \033[0m
ORANGE = \033[33m
PURPLE =  \033[0;35m
define ASCII_ART
$(ORANGE) 
                   


	··········································
	:[.......                                :
	:[..    [.. [.                           :
	:[..    [..   [. [..     [..    [..   [..:
	:[.......  [..[.  [..  [.   [..   [. [.. :
	:[..       [..[.   [..[..... [..   [.    :
	:[..       [..[.. [.. [.         [.  [.. :
	:[..       [..[..       [....   [..   [..:
	:             [..                        :
	··········································


$(RESET)
endef
export ASCII_ART

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
	@echo "$$ASCII_ART"
	@echo "$(GREEN)Compiling Pipex...$(RESET)"
	${CC} ${CFLAGS} ${OBJS} ${GNL} ${LIBFT} ${PRINTF} -o ${NAME}
	@echo "$(CYAN)Compilation completed!$(RESET)"


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
	@echo "$(GREEN)Cleaning...$(RESET)"
	rm -f ${NAME}
	rm -f a.out
	make -C ${LIBFT_DIR} fclean
	make -C ${PRINTF_DIR} fclean
	make -C ${GNL_DIR} fclean
	@echo "$(CYAN)Cleaned successfully!$(RESET)"

re:    fclean all

.PHONY: all clean fclean re