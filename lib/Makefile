##
## EPITECH PROJECT, 2018
## arcade
## File description:
## Graphical Makefile
##

NCURSES	=	make -C ./Ncurses
SFML	=	make -C ./Sfml
ALLEGRO	=	make -C ./Allegro
LCACA	=	make -C ./Libcaca

all	:
		export LD_LIBRARY_PATH=.
		$(NCURSES)
		$(SFML)
		$(ALLEGRO)
		$(LCACA)

clean	:
		$(NCURSES) clean
		$(SFML) clean
		$(ALLEGRO) clean
		$(LCACA) clean

fclean	:
		$(NCURSES) fclean
		$(SFML) fclean
		$(ALLEGRO) fclean
		$(LCACA) fclean

re	:
		$(NCURSES) re
		$(SFML) re
		$(ALLEGRO) re
		$(LCACA) re

.PHONY	:	all clean fclean re

coffee	:	all clean
