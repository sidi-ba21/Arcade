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

SRC             =       $(SRC_DIR)main.cpp              \

OBJ             =       $(SRC:.cpp=.o)

CPPFLAGS        =       -I include

CC              =               g++

CFLAGS  =       -std=c++20 -Wall -Wextra -Werror

all:    $(NAME)

$(NAME):        $(OBJ)
        $(CC) -o $(NAME) $(OBJ)

core:

games:

graphicals:

clean:
        $(RM) $(OBJ)

fclean: clean
        $(RM) $(NAME)

re:     fclean all

.PHONY: all core games graphicals clean fclean re
