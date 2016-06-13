/*
** Jason Brillante "Damdoshi"
** Hanged Bunny Studio 2014-2016
**
**
*/

#include		<stdio.h>
#include		<lapin.h>

int			main(void)
{
  char			*str;
  size_t		i;
  
  bunny_set_maximum_ram(2L * 1024L * 1024L * 1024L);
  if ((str = bunny_malloc(1.9L * 1024L * 1024L * 1024L)) == NULL)
    {
      puts("crac");
      return (0);
    }
  for (i = 0; i < 1.9L * 1024L * 1024L * 1024L; ++i)
    str[i] = rand();
  for (i = 0; i < 1.9L * 1024L * 1024L * 1024L; ++i)
    str[i] ^= i;
  return (0);
}

