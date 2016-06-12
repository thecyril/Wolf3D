/*
** my_isneg.c for my_isneg in /home/puccio_c/rendu/Infographie/gfx_wolf3d/lib/my
** 
** Made by cyril puccio
** Login   <puccio_c@epitech.net>
** 
** Started on  Sun Jan  3 14:15:21 2016 cyril puccio
** Last update Sun Jan  3 14:15:33 2016 cyril puccio
*/

int     my_isneg(char *str)
{
  int   i;
  int   counter;

  i = 0;
  counter = 0;
  while (str[i] < '0' || str[i] > '9')
    {
      if (str[i] == '-')
        counter++;
      i++;
    }
  if (counter % 2 == 0)
    return (0);
  else
    return (1);
}
