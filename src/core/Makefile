##
## EPITECH PROJECT, 2022
## Arcade
## File description:
## Makefile
##

NAME	=	arcade

SRC_CORE	=	Core.cpp	\
				main.cpp

CFLAGS	=	-std=c++20 -Wall -Wextra -Werror -fPIC `sdl2-config --cflags --libs`

LIBS	=	-lncurses -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -ldl -lstdc++fs -lSDL2 -lSDL2_image -lSDL2_ttf 

CC			=	g++

OBJ_CORE	=	$(SRC_CORE:.cpp=.o)

INC			=	../include

all: $(OBJ_CORE)
	$(CC) $(CFLAGS) $(OBJ_CORE) -o $(NAME) $(LIBS)
	mv $(NAME)	../../

clean:
	$(RM) $(OBJ_CORE)

fclean:	clean
	$(RM) ../../$(NAME)

re: fclean all

.PHONY: all clean fclean re