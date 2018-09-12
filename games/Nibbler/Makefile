##
## EPITECH PROJECT, 2018
## arcade
## File description:
## Nibbler Makefile
##

NAME	=	./../lib_arcade_nibbler.so

SRCS	=	Nibbler.cpp

OBJS	=	$(SRCS:.cpp=.o)

CXXFLAGS	=	-fPIC -W -Wall -Wextra -std=c++1z
CPPFLAGS	=	-I./../

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		g++ -shared -o $(NAME) $(OBJS)

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re

coffee	:	all clean
