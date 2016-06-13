
CC		=	gcc
NAME		=	template
LIB		=	-L/home/${USER}/.froot/lib/ -llapin \
			-lsfml-audio \
			-lsfml-graphics \
			-lsfml-window \
			-lsfml-system \
			-lstdc++ -ldl \
			-lm
FLAG		=	-W -Wall -ansi -pedantic -I/home/${USER}/.froot/include/
SRC		=	template.c
OBJ		=	$(SRC:.c=.o)

all:		$(NAME)
$(NAME):	$(OBJ)
		$(CC) $(OBJ) $(LIB) -o $(NAME)
clean:
		rm -f $(OBJ)
fclean:		clean
		rm -f $(NAME)
re:		fclean all
.c.o:
		$(CC) -c $< -o $@ $(FLAG)

