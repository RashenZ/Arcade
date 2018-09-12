##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Core Makefile
##

NAME	=	../arcade

SRCS	=	Menu/SelectGame.cpp	\
		Menu/UserName.cpp	\
		Menu/Option.cpp		\
		Menu/Menu.cpp		\
		Arcade.cpp	\
		main.cpp

OBJS	=	$(SRCS:.cpp=.o)

RM	=	rm -f

CXXFLAGS +=	-W -Wall -Wextra -std=c++14

CPPFLAGS +=	-I./../lib -I./../games

LIBS	=	-ldl

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		g++ -o $(NAME) $(OBJS) $(LIBS)

clean	:
		$(RM) $(OBJS)

fclean 	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re

coffee	:	all clean
