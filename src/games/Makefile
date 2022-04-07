##
## EPITECH PROJECT, 2022
## Arcade
## File description:
## Makefile
##

SRC_SNAKE	=	Snake.cpp

SRC_PACMAN	=	Pacman.cpp

CPPFLAGS	= -fPIC -std=c++20

LDFLAGS		=	-shared

OBJ_SNAKE	=	$(SRC_SNAKE:.cpp=.o)

OBJ_PACMAN	=	$(SRC_PACMAN:.cpp=.o)

INC			=	../include

LIB_DIR		=	../../lib/

LIB_SNAKE	=	arcade_nibbler.so

LIB_PACMAN	=	arcade_pacman.so

all: $(LIB_SNAKE) $(LIB_PACMAN)

$(LIB_SNAKE): $(OBJ_SNAKE)
	$(CC) $(CFLAGS) $(OBJ_SNAKE) -o $(LIB_SNAKE) $(LDFLAGS)
	mv $(LIB_SNAKE) $(LIB_DIR)

$(LIB_PACMAN): $(OBJ_PACMAN)
	$(CC) $(CFLAGS) $(OBJ_PACMAN) -o $(LIB_PACMAN) $(LDFLAGS)
	mv $(LIB_PACMAN) $(LIB_DIR)

clean:
	$(RM) $(OBJ_SNAKE) 
	$(RM) $(OBJ_PACMAN)

fclean:	clean
	$(RM) $(LIB_DIR)$(LIB_SNAKE) 
	$(RM) $(LIB_DIR)$(LIB_PACMAN)

re: fclean all

.PHONY: all clean fclean re