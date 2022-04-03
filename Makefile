##
## EPITECH PROJECT, 2022
## makefile
## File description:
## arcade makefile
##

NAME    =       arcade

SRC_DIR =       src/

LIB   	=	lib/

CORE	=	src/core/

GAMES	=	games/

GRAPHICALS	=	graphicals/

SRC			=	$(CORE)main.cpp              \
				$(CORE)Core.cpp				\

OBJ             =       $(SRC:.cpp=.o)

CPPFLAGS        =       -I include

CC              =               g++

CFLAGS  =       -std=c++20 -Wall -Wextra -Werror

all:	graphicals core

core:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -ldl -lstdc++fs

games:

graphicals:
	g++ entrypoint.cpp -shared -fPIC -o lib.so
	cp lib.so ./lib/

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) lib.so

re:	fclean all

.PHONY: all core games graphicals clean fclean re
