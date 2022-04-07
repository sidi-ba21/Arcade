##
## EPITECH PROJECT, 2022
## makefile
## File description:
## arcade makefile
##

NAME	=	arcade

SRC_DIR	=	src/

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
