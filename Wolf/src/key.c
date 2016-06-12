/*
** key.c for key in /home/puccio_c/rendu/Infographie/gfx_wolf3d/src
** 
** Made by cyril puccio
** Login   <puccio_c@epitech.net>
** 
** Started on  Sun Jan  3 18:26:27 2016 cyril puccio
** Last update Sun Jan  3 19:02:58 2016 cyril puccio
*/

#include <lapin.h>
#include <lapin_enum.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>
#include "struct.h"

bool		up(t_bunny_position pos, t_var *var,
		   t_bunny_position newpos)
{
  bool		check;
  check = 1;
  go(&pos, var->angl * M_PI / 180, &newpos, var->footstep);
  if (colide(&newpos, var) == 0)
    {
      var->posx = newpos.x;
      var->posy = newpos.y;
    }
  return (check);
}

bool		down(t_bunny_position pos, t_var *var,
		     t_bunny_position newpos)
{
  bool		check;
  check = 1;
  go(&pos, var->angl * M_PI / 180, &newpos, -var->footstep);
  if (colide(&newpos, var) == 0)
    {
      var->posx = newpos.x;
      var->posy = newpos.y;
    }
  return (check);
}

bool            left(t_var *var)
{
  bool		check;
  check = 1;
  var->angl = var->angl + 2.5;
  if (var->angl > 360)
    var->angl -= 360;
  return (check);
}

bool            right(t_var *var)
{
  bool          check;
  check= 1;
  var->angl = var->angl - 2.5;
  if (var->angl > 360)
    var->angl += 360;
  return (check);
}

t_bunny_response           key(t_bunny_event_state      state,
                               t_bunny_keysym           button,
                               void                     *data)
{
  (void)state; (void)button; (void)data;
  return (GO_ON);
}
