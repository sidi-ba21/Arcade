##
## EPITECH PROJECT, 2022
## makefile
## File description:
## arcade makefile
##

NAME	=	arcade

SRC_DIR	=	src/

CPPFLAGS	=	-I include

CC		=	g++

CFLAGS	=	-std=c++20 -Wall -Wextra -Werror -fPIC `sdl2-config --cflags --libs`

LIBS	=	-lncurses -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -ldl -lstdc++fs -lSDL2 -lSDL2_image -lSDL2_ttf 

all:	core graphicals games

core:
	$(MAKE) -C $(SRC_DIR)core

games:
	$(MAKE) -C $(SRC_DIR)games

graphicals:
	$(MAKE) -C $(SRC_DIR)graphicals

clean:
	$(MAKE) -C $(SRC_DIR)core clean
	$(MAKE) -C $(SRC_DIR)games clean
	$(MAKE) -C $(SRC_DIR)graphicals clean

fclean: clean
	$(MAKE) -C $(SRC_DIR)core fclean
	$(MAKE) -C $(SRC_DIR)games fclean
	$(MAKE) -C $(SRC_DIR)graphicals fclean

re:	fclean all

.PHONY: all core games graphicals clean fclean re
