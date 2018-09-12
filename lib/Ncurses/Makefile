##
## EPITECH PROJECT, 2018
## arcade
## File description:
## Ncurses Makefile
##

NAME	=	./../lib_arcade_ncurses.so

SRCS	=	Ncurses.cpp

OBJS	=	$(SRCS:.cpp=.o)

RM	=	rm -f

CXXFLAGS +=	-fPIC -W -Wall -Wextra -std=c++14
CPPFLAGS +=	-I./../

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		g++ -shared -o $(NAME) $(OBJS) -lncurses

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re

coffee	:	all clean
