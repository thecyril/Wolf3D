/*
** fonc2.c for fonc2 in /home/puccio_c/rendu/PSU_2015_my_printf
** 
** Made by cyril puccio
** Login   <puccio_c@epitech.net>
** 
** Started on  Sun Nov 15 16:25:21 2015 cyril puccio
** Last update Mon Nov 16 21:23:47 2015 cyril puccio
*/

#include <stdarg.h>

void		put_basemaj16(va_list list)
{
  int		nb;

  nb = va_arg(list, unsigned int);
  my_putnbr_base(nb, "0123456789ABCDEF");
}

void            put_base2(va_list list)
{
  int           nb;

  nb = va_arg(list, int);
  if (nb < 0)
    nb = nb * -1;
  my_putnbr_base(nb, "01");
}

void			put_unbr(va_list list)
{
  long long int		nb;
  long long int		i;

  nb = va_arg(list, int);
  if (nb < 0)
    i = 4294967296 + nb;
  my_put_nbr(i);
}

void                    put_phex(va_list list)
{
  void			*val;

  val = va_arg(list, void *);
  my_putstr("0x");
  my_putnbr_base(val, "0123456789abcdef");
}
