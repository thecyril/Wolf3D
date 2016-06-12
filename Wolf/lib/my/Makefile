##
## Makefile for Makefile in /home/puccio_c/rendu/Piscine_C_J10/lib/my
## 
## Made by cyril puccio
## Login   <puccio_c@epitech.net>
## 
## Started on  Fri Oct  9 18:40:22 2015 cyril puccio
## Last update Sun Jan  3 18:24:00 2016 cyril puccio
##

SRC	= my_putchar.c		\
	  my_putstr.c		\
	  my_strlen.c		\
	  my_strcmp.c		\
	  my_put_nbr.c		\
	  my_putnbr_base.c	\
	  my_str_isprintable.c	\
	  my_strlowcase.c	\
	  my_printf.c		\
	  my_getnbr.c		\
	  fonc.c		\
	  fonc2.c		\
	  tekpixel.c		\
	  vecnorm.c		\
	  my_isnum.c		\
	  my_atof.c		\
	  my_isneg.c		\

FLAGS   += -Wextra -Wall -Werror -pedantic
CFLAGS  += -I.

NAME	= libmy.a

CC	= cc

OBJ	= $(SRC:.c=.o)

HEADER	= my.h

all:	$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	cp -f $(NAME) ../../
	cp -f $(HEADER) ../../include
clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)
	rm -f ../../include/$(HEADER)

re:	fclean	all

.PHONY: all clean fclean re
