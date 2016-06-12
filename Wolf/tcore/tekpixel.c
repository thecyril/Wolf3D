/*
** tekpixel.c for tekpixel in /home/puccio_c/rendu/Infographie/gfx_wolf3d/lib/my
** 
** Made by cyril puccio
** Login   <puccio_c@epitech.net>
** 
** Started on  Thu Dec 24 14:42:12 2015 cyril puccio
** Last update Sun Jan  3 18:20:57 2016 cyril puccio
*/

#include <lapin.h>

void            tekpixel(t_bunny_pixelarray *pix,
                         t_bunny_position *pos,
                         t_color *color)
{
  ((t_color *)pix->pixels)[pos->x + pix->clipable.clip_width * pos->y]
    = *color;
}
