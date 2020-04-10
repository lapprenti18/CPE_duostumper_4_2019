##
## EPITECH PROJECT, 2020
## makefile
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/my_str_to_word_array.c	\
		src/open_file.c	\
		src/str_len_cmp.c	\
		src/tab.c	\

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
