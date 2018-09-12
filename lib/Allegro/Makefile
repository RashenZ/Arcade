##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## 
##

NAME	=	./../lib_arcade_allegro.so

SRCS	=	Allegro.cpp

OBJS	=	$(SRCS:.cpp=.o)

RM	=	rm -f

CXXFLAGS +=	-fPIC -W -Wall -Wextra -std=c++14
CPPFLAGS +=	-I./../

LIBS	=	-lallegro -lallegro_ttf -lallegro_image

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		g++ -shared -o $(NAME) $(OBJS) $(LIBS)

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
