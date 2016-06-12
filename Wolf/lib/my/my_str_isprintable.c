/*
** my_str_isprintable.c for my_str_isprintable in /home/puccio_c/rendu/Piscine_C_J07/lib/my
** 
** Made by cyril puccio
** Login   <puccio_c@epitech.net>
** 
** Started on  Wed Oct  7 11:24:11 2015 cyril puccio
** Last update Thu Nov  5 14:34:02 2015 cyril puccio
*/

int     my_str_isprintable(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= 32 && str[i] <= 126)
	i = i + 1;
      else
	return (0);
    }
  return (1);
}
