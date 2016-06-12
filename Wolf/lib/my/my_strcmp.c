/*
** my_strcmp.c for my_strcmp in /home/puccio_c/rendu/Piscine_C_J06/ex_06
** 
** Made by cyril puccio
** Login   <puccio_c@epitech.net>
** 
** Started on  Wed Oct  7 14:21:33 2015 cyril puccio
** Last update Sun Nov 29 20:13:09 2015 cyril puccio
*/

int     my_strcmp(char *s1, char *s2)
{
  int   i;
  char	c1;
  char	c2;

  i = 0;
  while (s1[i])
    {
      c1 = s1[i];
      c2 = s2[i];
      if (c1 >= 'A' && c1 <= 'Z')
	c1 = c1 + 32;
      if (c2 >= 'A' && c2 <= 'Z')
	c2 = c2 + 32;
      if (c1 < c2)
        return (-1);
      if (c1 > c2)
        return (1);
      i++;
    }
  return (0);
}
