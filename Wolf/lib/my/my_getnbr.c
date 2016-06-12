/*
** my_getnbr.c for my_getnbr in /home/puccio_c/rendu/Piscine_C_J07/lib/my
** 
** Made by cyril puccio
** Login   <puccio_c@epitech.net>
** 
** Started on  Thu Oct 15 20:06:58 2015 cyril puccio
** Last update Sun Jan  3 15:43:54 2016 cyril puccio
*/

int	my_getnbr(const char *str)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (my_isnum(str[i]) == 0)
    i++;
  while (my_isnum(str[i]) == 1)
    {
      nb = ((nb * 10) + (str[i] - 48));
      i++;
    }
  if (my_isneg(str) == 1)
    nb = nb * (-1);
  return (nb);
}
