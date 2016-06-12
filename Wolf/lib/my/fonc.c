/*
** flag.c for flag in /home/puccio_c/rendu/PSU_2015_my_printf
** 
** Made by cyril puccio
** Login   <puccio_c@epitech.net>
** 
** Started on  Mon Nov  9 11:54:20 2015 cyril puccio
** Last update Mon Nov 16 12:06:05 2015 cyril puccio
*/

#include        <stdarg.h>
#include	"struc.h"

void             put_str(va_list list)
{
  char		*str;

  str = va_arg(list, char *);
  my_putstr(str);
}

void		put_nbr(va_list list)
{
  int		nb;

  nb = va_arg(list, int);
  my_put_nbr(nb);
}

void		put_char(va_list list)
{
  char		c;

  c = va_arg(list, int);
  my_putchar(c);
}

void		put_base8(va_list list)
{
  int		nb;

  nb = va_arg(list, int);
  my_putnbr_base(nb, "01234567");
}

void            put_base16(va_list list)
{
  int		nb;

  nb = va_arg(list, int);
  my_putnbr_base(nb, "0123456789abcdef");
}
