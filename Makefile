##
## EPITECH PROJECT, 2022
## makefile
## File description:
## arcade makefile
##

NAME	=	arcade

SRC_DIR	=	src/

CORE	=	src/core/

SRC		=	$(CORE)main.cpp				\
				$(CORE)Core.cpp				\

OBJ		=	$(SRC:.cpp=.o)

CPPFLAGS	=	-I include

CC		=	g++

CFLAGS	=	-std=c++20 -Wall -Wextra -Werror -fPIC `sdl-config --cflags --libs`

LIBS	=	-lncurses -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -ldl -lstdc++fs -lSDL2 -lSDL2_image -lSDL2_ttf

all:	games graphicals core

core:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIBS)

games:
	$(MAKE) -C ./games

graphicals:
	$(MAKE) -C ./lib

clean:
	$(RM) $(OBJ)
	$(MAKE) -C ./games clean
	$(MAKE) -C ./lib clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C ./games fclean
	$(MAKE) -C ./lib fclean

re:	fclean all

.PHONY: all core games graphicals clean fclean re
