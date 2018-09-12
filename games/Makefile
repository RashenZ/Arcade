##
## EPITECH PROJECT, 2018
## arcade
## File description:
## Games Makefile
##

PACMAN	=	make -C ./Pacman
NIBBLER	=	make -C ./Nibbler

all	:
		export LD_LIBRARY_PATH=.
		$(PACMAN)
		$(NIBBLER)

clean	:
		$(PACMAN) clean
		$(NIBBLER) clean

fclean	:
		$(PACMAN) fclean
		$(NIBBLER) fclean

re	:	fclean all

.PHONY	:	all clean fclean re

coffee	:	all clean
