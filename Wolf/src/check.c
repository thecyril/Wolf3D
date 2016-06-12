/*
** check.c for check in /home/puccio_c/rendu/Infographie/gfx_wolf3d/src
** 
** Made by cyril puccio
** Login   <puccio_c@epitech.net>
** 
** Started on  Sun Jan  3 17:52:52 2016 cyril puccio
** Last update Sun Jan  3 19:03:03 2016 cyril puccio
*/

#include <lapin.h>
#include <lapin_enum.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>
#include "struct.h"

void            raychecker(t_var *var, int mapw, int maph,
			   t_bunny_pixelarray *pix)
{
  var->a = var->angl + var->chpv / 2;
  var->a_rad = M_PI * var->a / 180;
  while (var->a >= (var->angl - var->chpv / 2))
    {
      ampl_checker(var, mapw, maph, pix);
      var->a = var->a - var->stepang;
      var->a_rad = M_PI * var->a / 180;
    }
}

bool		touch(int rayamp, bool hit, t_var *var,
		      t_bunny_pixelarray *pix)
{
  double        eray;

  rayamp--;
  eray = 0;
  var->posckx = var->posx + rayamp * var->stepdir * cos(var->a_rad);
  var->poscky = var->posy + rayamp * var->stepdir * sin(var->a_rad);
  while (my_getnbr(pos((var->posckx / var->dmcb),
		       (var->poscky / var->dmcb), var)) == 0)
    {
      eray++;
      var->posckx = var->posx + (rayamp + eray / 5)
	* var->stepdir * cos(var->a_rad);
      var->poscky = var->posy + (rayamp + eray / 5)
	* var->stepdir * sin(var->a_rad);
    }
  var->cote = detcote(var->posckx, var->poscky, var);
  line_tracer(wallh((rayamp + eray / 5) * var->stepdir, var->a - var->angl,
		    &var), var->a - var->angl, var->chpv, pix, var);
  hit = true;
  return (hit);
}

void            ampl_checker(t_var *var, int mapw, int maph,
			     t_bunny_pixelarray *pix)
{
  bool          hit;
  int           rayamp;

  rayamp = 2;
  hit = false;
  var->posckx = var->posx;
  var->poscky = var->posy;
  while (!hit && var->posckx <= mapw * var->dmcb
	 && var->poscky <= maph * var->dmcb)
    {
      var->posckx = var->posx + rayamp * var->stepdir * cos(var->a_rad);
      var->poscky = var->posy + rayamp * var->stepdir * sin(var->a_rad);
      if (my_getnbr(pos((var->posckx / var->dmcb),
			(var->poscky / var->dmcb), var)) > 0)
        {
          hit = touch(rayamp, hit, var, pix);
        }
      rayamp++;
    }
}

bool            colide(t_bunny_position *newpos, t_var *var)
{
  if (my_getnbr(pos((newpos->x / var->dmcb),
                    (newpos->y / var->dmcb), var)) > 0)
    return (1);
  return (0);
}
