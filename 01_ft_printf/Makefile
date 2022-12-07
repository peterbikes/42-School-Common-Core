RM = rm -rf

CC = cc

NAME = libftprintf.a

SOURCES = ft_putchar.c ft_putnbr.c ft_putstr.c ft_puthexaupcase.c ft_puthexalocase.c ft_putpointer.c ft_printf.c ft_putnbr_unsigned.c

OBJECTS = ${SOURCES:.c=.o}

${NAME}: ${OBJECTS}
	ar rc ${NAME} ${OBJECTS}

all: ${NAME}

clean:
	${RM} ${OBJECTS}

fclean: clean
	${RM} ${NAME}

re: fclean all
