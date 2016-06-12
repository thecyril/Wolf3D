/*
** putstr.c for my_putstr in /home/puccio_c/rendu/Piscine_C_J04
** 
** Made by cyril puccio
** Login   <puccio_c@epitech.net>
** 
** Started on  Thu Oct  1 14:06:48 2015 cyril puccio
** Last update Tue Dec 15 11:11:05 2015 cyril puccio
*/

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
  return (0);
}
