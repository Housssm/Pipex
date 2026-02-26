RED     = \033[31m
GREEN   = \033[32m
CYAN    = \033[36m
RESET   = \033[0m
ORANGE  = \033[33m
PURPLE  = \033[0;35m

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
	Src/main.c \
	Src/first_step.c \
	Src/parsing.c \
	Src/pipex_utils.c \
	Src/executable.c

BONUS_SRCS = \
	Src/main_bonus.c \
	Src/heredoc_bonus.c

COMMON_SRCS = \
	Src/first_step.c \
	Src/parsing.c \
	Src/pipex_utils.c \
	Src/executable.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(COMMON_SRCS:.c=.o) $(BONUS_SRCS:.c=.o)

NAME = pipex
HEADER = pipex.h

LIBFT_DIR = ./Libft/libft
LIBFT = ${LIBFT_DIR}/libft.a

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "$$ASCII_ART"
	@echo "$(GREEN)Compiling Pipex...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(CYAN)Compilation completed!$(RESET)"

bonus: $(LIBFT) $(BONUS_OBJS)
	rm -f Src/main.o
	@echo "$$ASCII_ART"
	@echo "$(GREEN)Compiling Pipex with Bonus...$(RESET)"
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(NAME)
	@echo "$(CYAN)Bonus compilation completed!$(RESET)"

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	@echo "$(GREEN)Cleaning...$(RESET)"
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	@echo "$(CYAN)Cleaned successfully!$(RESET)"

re: fclean all

.PHONY: all bonus clean fclean re

