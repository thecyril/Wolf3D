NAME    =       wolf3d

FLAGS   =	-W -Wall -Werror -ansi -pedantic 		\
		-I/home/${USER}/.froot/lib                      \
		-I/home/${USER}/.froot/include

CFLAGS  =       -I include

LAPIN   =       -L/home/${USER}/.froot/lib/ -llapin     \
		-L/usr/local/lib                        \
		-L/home/${USER}/.froot/include          \
		-lsfml-audio                            \
		-lsfml-graphics                         \
		-lsfml-window                           \
		-lsfml-system                           \
		-lstdc++                                \
		-ldl                                    \
		-lm

SRC     =       src/wolf3d.c            \
		src/check.c		\
		src/key.c		\
		src/trace.c		\
		src/pos.c

OBJ     =       $(SRC:.c=.o)

LIB     =       libmy.a

all     :       $(NAME)

$(NAME) :       $(LIB) $(OBJ)
		gcc $(SRC) $(LAPIN) $(CFLAGS) $(FLAGS) -o $(NAME) -L. -lmy

$(LIB) :
		make -C ./lib/my

clean   :
	 	rm -f $(OBJ)
		make clean -C ./lib/my

fclean  :
		rm -f $(OBJ)
		rm -f $(NAME)
		rm -f $(LIB)
		make fclean -C ./lib/my

re      :       fclean all

.PHONY  :       all clean fclean re
