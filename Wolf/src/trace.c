/*
** trace.c for trace in /home/puccio_c/rendu/Infographie/gfx_wolf3d/src
** 
** Made by cyril puccio
** Login   <puccio_c@epitech.net>
** 
** Started on  Sun Jan  3 19:04:00 2016 cyril puccio
** Last update Mon Feb 29 17:24:46 2016 cyril puccio
*/

#include <lapin.h>
#include <lapin_enum.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>
#include "struct.h"

#define DARK_GREEN      0XFF69BFA4
#define GREY            0XFFa3a3a3
#define LIGHT_GRAY      0XFFCCCCCC
#define LIGHT_GREY      0XFFb7b7b7
#define DARK_GRAY       0xFF8e8e8e

void                    fillpixel(t_bunny_pixelarray *pix, int desx,
                                  int desy, t_color color, t_var *var)
{
  t_bunny_position      pos;
  int                   i;

  i = 0;
  pos.y = desy;
  while (i < var->res)
    {
      pos.x = desx + i;
      tekpixel(pix, &pos, &color);
      i++;
    }
}

int             detcote(int x, int y, t_var *var)
{
  int           dx;
  int           dy;
  int           cote;

  dx = x - (x / var->dmcb + 0.5) * var->dmcb;
  dy = y - (y / var->dmcb + 0.5) * var->dmcb;
  if (abs(dx) > abs(dy))
    {
      cote  = 4;
      if (dx < 0)
        cote = 2;
      return (cote);
    }
  else
    cote = 1;
  if (dy > 0)
    cote = 3;
  return (cote);
}

int             wall_color(int cote)
{
  if (cote == 1)
    return (GREY);
  if (cote == 2)
    return (LIGHT_GREY);
  if (cote == 3)
    return (DARK_GRAY);
  else
    return (LIGHT_GRAY);
}
