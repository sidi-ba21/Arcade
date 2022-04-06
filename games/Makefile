##
## EPITECH PROJECT, 2022
## Arcade
## File description:
## Makefile
##

SRC_SNAKE	=	../src/games/Snake.cpp

SRC_PACMAN	=	../src/games/Pacman.cpp

CPPFLAGS	= -fPIC -std=c++20

LDFLAGS		=	-shared

OBJ_SNAKE	=	$(SRC_SNAKE:.cpp=.o)

OBJ_PACMAN	=	$(SRC_PACMAN:.cpp=.o)

INC			=	../include

LIB_SNAKE	=	arcade_nibbler.so

LIB_PACMAN	=	arcade_pacman.so

all: $(LIB_SNAKE) $(LIB_PACMAN)

$(LIB_SNAKE): $(OBJ_SNAKE)
	$(CC) $(CFLAGS) $(OBJ_SNAKE) -o $(LIB_SNAKE) $(LDFLAGS)
	mv $(LIB_SNAKE) ../lib

$(LIB_PACMAN): $(OBJ_PACMAN)
	$(CC) $(CFLAGS) $(OBJ_PACMAN) -o $(LIB_PACMAN) $(LDFLAGS)
	mv $(LIB_PACMAN) ../lib

clean:
	rm -f $(OBJ_SNAKE) $(OBJ_PACMAN)

fclean:
	rm -f ../lib/$(LIB_SNAKE) ../lib/$(LIB_PACMAN)

re: fclean all

.PHONY: all clean fclean re