/*
** pos.c for pos in /home/puccio_c/rendu/Infographie/gfx_wolf3d/src
** 
** Made by cyril puccio
** Login   <puccio_c@epitech.net>
** 
** Started on  Sun Jan  3 19:11:38 2016 cyril puccio
** Last update Sun Jan  3 19:21:44 2016 cyril puccio
*/

#include <lapin.h>
#include <lapin_enum.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>
#include "struct.h"

#define SCREEN_W        800
#define SCREEN_H        600

const char      *pos(int x, int y, t_var *var)
{
  int           w;
  int           h;
  int           i;

  w = my_getnbr(bunny_ini_get_field(var->ini, "map", "width", 0));
  h = my_getnbr(bunny_ini_get_field(var->ini, "map", "height", 0));
  i = ((h - 1) - y) * w + x;
  return (bunny_ini_get_field(var->ini, "map", "data", i));
}

int             wallh(int dist, double angl, t_var **var)
{
  int           hwall;

  hwall = (*var)->dmcb / (dist * cos(angl * M_PI /180))
    * (*var)->Wscreen / 2 / tan((*var)->chpv / 2 * M_PI / 180);
  return (hwall);
}

void            go(t_bunny_position *curpos,
                   double angle,
                   t_bunny_position *newpos,
                   int move)
{
  newpos->x = curpos->x + move * cos(angle);
  newpos->y = curpos->y + move * sin(angle);
}
