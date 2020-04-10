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

CC =	gcc

all	: $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(ERROR) $(VG) $(SRC) -o $(NAME)

clean	:
	$(RM) $(OBJ)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all
