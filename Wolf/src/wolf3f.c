/*
** wolf3d.c for wolf3d in /home/puccio_c/rendu/Infographie/gfx_wolf3d/src
** 
** Made by cyril puccio
** Login   <puccio_c@epitech.net>
** 
** Started on  Thu Dec 24 13:17:58 2015 cyril puccio
** Last update Tue Jan 26 17:40:35 2016 cyril puccio
*/

#include <lapin.h>
#include <lapin_enum.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>
#include "struct.h"

#define SCREEN_W	800
#define	SCREEN_H	600
#define DARK_GREY       0XFF7a7a7a

void                    line_tracer(int hwall, double angle, double chpv,
                                    t_bunny_pixelarray *pix, t_var *var)
{
  t_color               color;
  int                   desx;
  int                   desy;
  int                   stop;

  desx = SCREEN_W * (0.5 + -angle / chpv);
  desy = 0;
  stop = SCREEN_H / 2 - hwall / 2;
  color.full = BLUE;
  while (desy++ < stop)
    fillpixel(pix, desx, desy, color, var);
  stop = hwall / 2 + SCREEN_H / 2;
  color.full = wall_color(var->cote);
  while (desy++ < stop)
    fillpixel(pix, desx, desy, color, var);
  stop = SCREEN_H;
  color.full = DARK_GREY;
  while (desy++ < stop)
    fillpixel(pix, desx, desy, color, var);
}

void			fill_struct(t_var *var, t_bunny_ini *ini)
{
  var->res = 2;
  var->dmcb = 100;
  var->posx = (my_getnbr(bunny_ini_get_field(ini, "map", "start_position", 0))
	       + 0.5) * var->dmcb;
  var->posy = (my_getnbr(bunny_ini_get_field(ini, "map", "start_position", 1))
	       + 0.5) * var->dmcb;
  var->angl = my_atof(bunny_ini_get_field(ini, "map", "start_position", 2));
  var->footstep = var->dmcb / 10;
  var->chpv = 75;
  var->Wscreen = SCREEN_W;
  var->stepdir = var->dmcb * 0.1;
  var->stepang = (var->chpv / SCREEN_W - 0.001) * var->res;
  var->start.x = 0;
  var->start.y = 0;
  var->pix = bunny_new_pixelarray(SCREEN_W, SCREEN_H);
  var->mapw = my_getnbr(bunny_ini_get_field(var->ini, "map", "width", 0));
  var->maph = my_getnbr(bunny_ini_get_field(var->ini, "map", "height", 0));
}

t_bunny_response                mainloop(t_var *var)
{
  const bool   			*touche;
  t_bunny_position		pos;
  t_bunny_position		newpos;
  bool				check;

  touche = bunny_get_keyboard();
  pos.x = var->posx;
  pos.y = var->posy;
  bunny_blit(&var->win->buffer, &var->pix->clipable, &var->start);
  if (touche[BKS_UP] == 1)
    check = up(pos, var, newpos);
  if (touche[BKS_DOWN] == 1)
    check = down(pos, var, newpos);
  if (touche[BKS_RIGHT] == 1)
    check = right(var);
  if (touche[BKS_LEFT] == 1)
    check = left(var);
  if (check == 1)
    raychecker(var, var->mapw, var->maph, var->pix);
  bunny_display(var->win);
  if (touche[BKS_ESCAPE] == 1)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

int			wolf(char *map)
{
  t_var                 var;

  var.win = bunny_start(SCREEN_W, SCREEN_H, false, "main");
  var.ini = bunny_load_ini(map);
  if (var.ini == NULL)
    {
      my_putstr ("Fichier introuvable\n");
      return (-1);
    }
  if (var.win == 0)
    return (-1);
  fill_struct(&var, var.ini);
  if (var.pix == NULL)
    return (-1);
  raychecker(&var, var.mapw, var.maph, var.pix);
  bunny_blit(&var.win->buffer, &var.pix->clipable, &var.start);
  bunny_display(var.win);
  bunny_set_loop_main_function((t_bunny_loop)mainloop);
  bunny_set_key_response(key);
  bunny_loop(var.win, 80, &var);
  bunny_delete_ini(var.ini);
  bunny_stop(var.win);
  bunny_delete_clipable(&var.pix->clipable);
  return (0);
}

int			main(int ac, char **av)
{
  if (ac > 1)
    {
      wolf(av[1]);
    }
  else
    return (0);
  return (0);
}
