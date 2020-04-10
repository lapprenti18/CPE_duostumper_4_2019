##
## EPITECH PROJECT, 2020
## makefile
## File description:
## Makefile
##

SRC	=	src/main.c	\

NAME	=	mixword

VG	=	-g3

ERROR	=	-Wall -W -Wextra

all	:
	gcc -o $(NAME) $(SRC) $(ERROR)

clean	:
	rm -f *.o $(OBJ)

fclean	: clean
	rm -f $(NAME)

re	: fclean all
