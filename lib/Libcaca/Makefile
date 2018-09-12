##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## 
##

NAME	=	./../lib_arcade_libcaca.so

SRCS	=	Libcaca.cpp

OBJS	=	$(SRCS:.cpp=.o)

RM	=	rm -f

CXXFLAGS +=	-fPIC -W -Wall -Wextra -std=c++14
CPPFLAGS +=	-I./../

LIBS	=	`pkg-config --libs --cflags caca`

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		g++ $(LIBS) -shared -o $(NAME) $(OBJS)

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
