##
## EPITECH PROJECT, 2022
## makefile
## File description:
## arcade makefile
##

NAME    =       arcade

SRC_DIR =       src/

LIB   	=	lib/

CORE	=	core/

GAMES	=	games/

GRAPHICALS	=	graphicals/

SRC             =       main.cpp              \

OBJ             =       $(SRC:.cpp=.o)

CPPFLAGS        =       -I include

CC              =               g++

CFLAGS  =       -std=c++20 -Wall -Wextra -Werror

all:	core graphicals

core:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -ldl

games:

graphicals:
	gcc test.c -shared -fPIC -o lib.so $(INC)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) lib.so

re:	fclean all

.PHONY: all core games graphicals clean fclean re
