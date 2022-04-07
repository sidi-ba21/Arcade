##
## EPITECH PROJECT, 2022
## Arcade
## File description:
## Makefile
##

SRC_NCURSES	=	Ncurses.cpp

SRC_SDL		=	Sdl.cpp

SRC_SFML	=	Sfml.cpp

CPPFLAGS	= -fPIC -std=c++20

LDFLAGS		=	-shared

OBJ_NCURSES	=	$(SRC_NCURSES:.cpp=.o)

OBJ_SDL		=	$(SRC_SDL:.cpp=.o)

OBJ_SFML	=	$(SRC_SFML:.cpp=.o)

INC			=	../include

LIB_DIR		=	../../lib/

LIB_NCURSES	=	arcade_ncurses.so

LIB_SDL		=	arcade_sdl2.so

LIB_SFML		=	arcade_sfml.so

all: $(LIB_NCURSES) $(LIB_SDL) $(LIB_SFML)

$(LIB_NCURSES): $(OBJ_NCURSES)
	$(CC) $(CFLAGS) $(OBJ_NCURSES) -o $(LIB_NCURSES) $(LDFLAGS)
	mv $(LIB_NCURSES) $(LIB_DIR)

$(LIB_SDL): $(OBJ_SDL)
	$(CC) $(CFLAGS) $(OBJ_SDL) -o $(LIB_SDL) $(LDFLAGS)
	mv $(LIB_SDL) $(LIB_DIR)

$(LIB_SFML): $(OBJ_SFML)
	$(CC) $(CFLAGS) $(OBJ_SFML) -o $(LIB_SFML) $(LDFLAGS)
	mv $(LIB_SFML) $(LIB_DIR)

clean:
	$(RM) $(OBJ_NCURSES) 
	$(RM) $(OBJ_SDL) 
	$(RM) $(OBJ_SFML)

fclean:	clean
	$(RM) $(LIB_DIR)$(LIB_NCURSES)
	$(RM) $(LIB_DIR)$(LIB_SDL)
	$(RM) $(LIB_DIR)$(LIB_SFML)

re: fclean all

.PHONY: all clean fclean re