

NAME		=	script
LIB		=	-L/home/${USER}/.froot/lib/ -llapin \
			-L/usr/local/lib \
			-lsfml-audio \
			-lsfml-graphics \
			-lsfml-window \
			-lsfml-system \
			-lstdc++ -lm -ldl
FLAG		=	-W -Wall -Werror -ansi -pedantic -g -g3 -ggdb
SRC		=	$(wildcard ./*.c)
OBJ		=	$(SRC:.c=.o)


all:		$(NAME)
$(NAME):	$(OBJ)
		gcc $(OBJ) $(LIB) -o ${NAME}
clean:
		rm -f $(OBJ)
fclean:		clean
		rm -f $(NAME)
re:		fclean all
.c.o:
	gcc -c $< -o $@ $(FLAG)

