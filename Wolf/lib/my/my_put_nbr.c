/*
** my_put_nbr.c for my_put_nbr in /home/puccio_c/rendu/Piscine_C_J03
** 
** Made by cyril puccio
** Login   <puccio_c@epitech.net>
** 
** Started on  Fri Oct  2 11:34:25 2015 cyril puccio
** Last update Tue Nov 24 18:41:30 2015 cyril puccio
*/

void    my_put_nbr(int nb)
{
  int   neg;

  neg = 0;
  if (nb < 0)
    {
      my_putchar('-');
      if (nb == -2147483648)
        {
          neg = 1;
          nb++;
        }
      nb = nb * -1;
    }
  if (nb >= 10)
    my_put_nbr(nb / 10);
  if (neg == 1)
    {
      neg = 0;
      my_putchar(nb % 10 + '1');
    }
  else
    my_putchar(nb % 10 + '0');
}
