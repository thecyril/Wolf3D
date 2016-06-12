/*
** go.c for go in /home/puccio_c/rendu/Infographie/gfx_wolf3d/tcore
** 
** Made by cyril puccio
** Login   <puccio_c@epitech.net>
** 
** Started on  Sun Jan  3 12:32:46 2016 cyril puccio
** Last update Sun Jan  3 12:37:34 2016 cyril puccio
*/

#include <lapin.h>

void            go(t_bunny_position *curpos,
                   double angle,
                   t_bunny_position *newpos,
                   int move)
{
  newpos->x = curpos->x + move * cos(angle);
  newpos->y = curpos->y + move * sin(angle);
}
