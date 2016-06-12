/*
** my_putnbr_base.c for my_putnbr_base in /home/puccio_c/rendu/Piscine_C_J07/lib/my
** 
** Made by cyril puccio
** Login   <puccio_c@epitech.net>
** 
** Started on  Sat Oct 17 14:57:13 2015 cyril puccio
** Last update Sun Nov 15 16:21:07 2015 cyril puccio
*/

void    my_putnbr_base(int nb, char *base)
{
  int   result;
  int   diviseur;
  int   size_base;

  size_base = my_strlen(base);
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  diviseur = 1;
  while ((nb / diviseur) >= size_base)
    diviseur = diviseur * size_base;
  while (diviseur > 0)
    {
      result = (nb /diviseur) % size_base;
      my_putchar(base[result]);
      diviseur = diviseur / size_base;
    }
}
