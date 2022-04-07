##
## EPITECH PROJECT, 2022
## Arcade
## File description:
## Makefile
##

NAME	=	arcade

SRC_CORE	=	Core.cpp	\
				main.cpp

CPPFLAGS	= -fPIC -std=c++20

LDFLAGS		=	-lstdc++fs -ldl

CC			=	g++

OBJ_CORE	=	$(SRC_CORE:.cpp=.o)

INC			=	../include

all: $(OBJ_CORE)
	$(CC) $(CFLAGS) $(OBJ_CORE) -o $(NAME) $(LDFLAGS) -g3
	mv $(NAME)	../../

clean:
	$(RM) $(OBJ_CORE)

fclean:	clean
	$(RM) ../../$(NAME)

re: fclean all

.PHONY: all clean fclean re