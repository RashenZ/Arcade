##
## EPITECH PROJECT, 2018
## arcade
## File description:
## Sfml Makefile
##

NAME	=	./../lib_arcade_sfml.so

SRCS	=	Sfml.cpp

OBJS	=	$(SRCS:.cpp=.o)

RM	=	rm -f

CXXFLAGS +=	-fPIC -W -Wall -Wextra
CPPFLAGS +=	-I./../

LIBS	=	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		g++ -shared -o $(NAME) $(OBJS) $(LIBS) 

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re

coffee	:	all clean
