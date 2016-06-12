/*
** my_printf.c for my_printf in /home/puccio_c/rendu/PSU_2015_my_printf
** 
** Made by cyril puccio
** Login   <puccio_c@epitech.net>
** 
** Started on  Thu Nov  5 16:48:35 2015 cyril puccio
** Last update Sun Jan  3 15:26:45 2016 cyril puccio
*/

#include        <stdlib.h>
#include        <stdarg.h>
#include	"struc.h"

void             init(t_struct *ptr)
{
  ptr[0].c = 's';
  ptr[0].ptr = put_str;
  ptr[1].c = 'd';
  ptr[1].ptr = put_nbr;
  ptr[2].c = 'c';
  ptr[2].ptr = put_char;
  ptr[3].c = 'b';
  ptr[3].ptr = put_base2;
  ptr[4].c = 'o';
  ptr[4].ptr = put_base8;
  ptr[5].c = 'x';
  ptr[5].ptr = put_base16;
  ptr[6].c = 'X';
  ptr[6].ptr = put_basemaj16;
  ptr[7].c = 'u';
  ptr[7].ptr = put_unbr;
  ptr[8].c = 'i';
  ptr[8].ptr = put_nbr;
  ptr[9].c = 'p';
  ptr[9].ptr = put_phex;
}

void		structure(char *str, va_list ap)
{
  t_struct	struc[10];
  int		j;

  j = 0;
  init(struc);
  while (j != 10)
    {
      if (str[0] == struc[j].c)
	struc[j].ptr(ap);
      j++;
    }
}

void		my_printf(char *str, ...)
{
  va_list	ap;
  int		i;

  va_start(ap, str);
  i = 0;
  while (str[i])
    {
      if (str[i] == '%')
	{
	  i += 1;
	  if (str[i] == '%')
	    my_putchar('%');
	  else
	    structure(str + i, ap);
	}
      else
	my_putchar(str[i]);
      i++;
    }
}
