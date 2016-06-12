/*
** my_atof.c for my_atof in /home/puccio_c/rendu/Infographie/gfx_wolf3d/lib/my
** 
** Made by cyril puccio
** Login   <puccio_c@epitech.net>
** 
** Started on  Sun Jan  3 13:42:53 2016 cyril puccio
** Last update Sun Jan  3 15:46:45 2016 cyril puccio
*/

double		my_atof(char *str)
{
  int		div;
  double	val;
  int		i;

  val = 0.0;
  div = 0;
  i = 0;
  while (my_isnum(str[i]) == 0)
    i++;
  while (str[i] && my_isnum(str[i]) == 1)
    val = val * 10.0 + (str[i++] - '0');
  if (str[i] == '.')
    {
      i++;
      while (str[i] && my_isnum(str[i]) == 1)
  	{
  	  val = val * 10.0 + (str[i++] - '0');
  	  div = div - 1;
  	}
    }
  while (div++ < 0)
      val = val * 0.1;
  if (my_isneg(str) == 1)
    val = val * (-1);
  return (val);
}
