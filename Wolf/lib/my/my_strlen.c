/*
** my_strlen.c for my_strlen in /home/puccio_c/rendu/Piscine_C_J04
** 
** Made by cyril puccio
** Login   <puccio_c@epitech.net>
** 
** Started on  Thu Oct  1 19:31:59 2015 cyril puccio
** Last update Tue Dec 15 11:11:14 2015 cyril puccio
*/

int	my_strlen(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}
