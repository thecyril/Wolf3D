/*
** my_strlowcase.c for my_strlowcase in /home/puccio_c/rendu/Piscine_C_J07/lib/my
** 
** Made by cyril puccio
** Login   <puccio_c@epitech.net>
** 
** Started on  Wed Oct  7 11:11:33 2015 cyril puccio
** Last update Sun Nov 29 18:50:19 2015 cyril puccio
*/

char    *my_strlowcase(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= 65 && str[i] <= 90)
	str[i] = str[i] + 32;
      i++;
    }
  return (str);
}
