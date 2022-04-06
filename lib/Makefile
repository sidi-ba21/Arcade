##
## EPITECH PROJECT, 2022
## Arcade
## File description:
## Makefile
##

SRC_NCURSES	=	../src/graphicals/Ncurses.cpp

SRC_SDL		=	../src/graphicals/Sdl.cpp

SRC_SFML	=	../src/graphicals/Sfml.cpp

CPPFLAGS	= -fPIC -std=c++20

LDFLAGS		=	-shared

OBJ_NCURSES	=	$(SRC_NCURSES:.cpp=.o)

OBJ_SDL		=	$(SRC_SDL:.cpp=.o)

OBJ_SFML	=	$(SRC_SFML:.cpp=.o)

INC			=	../include

LIB_NCURSES	=	arcade_ncurses.so

LIB_SDL		=	arcade_sdl2.so

LIB_SFML		=	arcade_sfml.so

all: $(LIB_NCURSES) $(LIB_SDL) $(LIB_SFML)

$(LIB_NCURSES): $(OBJ_NCURSES)
	$(CC) $(CFLAGS) $(OBJ_NCURSES) -o $(LIB_NCURSES) $(LDFLAGS)

$(LIB_SDL): $(OBJ_SDL)
	$(CC) $(CFLAGS) $(OBJ_SDL) -o $(LIB_SDL) $(LDFLAGS)

$(LIB_SFML): $(OBJ_SFML)
	$(CC) $(CFLAGS) $(OBJ_SFML) -o $(LIB_SFML) $(LDFLAGS)

clean:
	rm -f $(OBJ_NCURSES) $(OBJ_SDL) $(OBJ_SFML)

fclean:
	rm -f $(LIB_NCURSES) $(LIB_SDL) $(LIB_SFML)

re: fclean all

.PHONY: all clean fclean re