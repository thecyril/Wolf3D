/*
** my_isnum.c for my_isnum in /home/puccio_c/rendu/Infographie/gfx_wolf3d/lib/my
** 
** Made by cyril puccio
** Login   <puccio_c@epitech.net>
** 
** Started on  Sun Jan  3 13:51:57 2016 cyril puccio
** Last update Sun Jan  3 13:53:14 2016 cyril puccio
*/

int    	my_isnum(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}
