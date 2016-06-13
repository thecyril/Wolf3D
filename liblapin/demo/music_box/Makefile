

NAME		=	music
LIB		=	-L/home/${USER}/.froot/lib/ -llapin \
			-lsfml-audio \
			-lsfml-graphics \
			-lsfml-window \
			-lsfml-system \
			-lstdc++ -lm
FLAG		=	-W -Wall -Werror
SRC		=	$(wildcard ./*.c)
OBJ		=	$(SRC:.c=.o)


all:		$(NAME)
$(NAME):	$(OBJ)
		gcc $(OBJ) $(LIB) -o music
clean:
		rm -f $(OBJ)
fclean:		clean
		rm -f $(NAME)
re:		fclean all
.c.o:
	gcc -c $< -o $@ $(FLAG)

