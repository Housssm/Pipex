LIBC =    ft_print_char.c ft_print_percent.c ft_print_dec.c  \
	ft_print_str.c ft_print_unsigned.c ft_print_hexa_lower.c \
	ft_print_hexa_upper.c ft_print_adress.c ft_printf.c

SRCS = ${LIBC} 

SRCSALL = ${LIBC}

OBJS = ${SRCS:.c=.o}

OBJSALL = ${SRCSALL:.c=.o}

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra 

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:    ${OBJS}
	ar -rsc ${NAME} ${OBJS}

all:     ${NAME}

clean:    
	rm -f ${OBJSALL}

fclean:    clean;
	rm -f ${NAME}

re:    fclean all

.PHONY: all clean fclean re

.SILENT :