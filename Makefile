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

OBJ	= $(SRC:.c.o)

all	: $(NAME)
$(NAME):	$(OBJ)
	gcc $(ERROR) $(VG) $(SRC) -o -$(NAME)

clean	:
	rm -f $(OBJ)

fclean	: clean
	rm -f $(NAME)

re	: fclean all
