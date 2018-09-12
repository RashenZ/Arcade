## Makefile
## File description:
## 
##

CORE	=	make -C ./core
GAMES	=	make -C ./games
GRAPH	=	make -C ./lib

all	:
		$(CORE)
		$(GAMES)
		$(GRAPH)

core	:
		$(CORE)

games	:
		$(GAMES)

graphicals :
		$(GRAPH)

clean	:
		$(CORE) clean
		$(GAMES) clean
		$(GRAPH) clean

fclean	:
		$(CORE) fclean
		$(GAMES) fclean
		$(GRAPH) fclean

re	:	fclean all

.PHONY	:	all core games graphical clean fclean re

coffee	:	all clean
