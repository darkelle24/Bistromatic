##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	src/evalstr.c	\
		src/infinityminus.c	\
		src/my_strlen.c	\
		src/chartoint.c	\
		src/infinitymodulo.c	\
		src/infinitydivi.c	\
		src/reverse+print.c	\
		src/main+erreur.c	\
		src/my_putstr.c	\
		src/infinityadd.c	\
		src/infinitymulti.c	\
		src/inttochar.c	\
		src/reduchar.c

OBJ	=	$(SRC:.c=.o)

NAME	=	calc

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
