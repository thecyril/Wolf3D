/*
** vecnorm.c for vecnorm in /home/puccio_c/rendu/Infographie/gfx_wolf3d
** 
** Made by cyril puccio
** Login   <puccio_c@epitech.net>
** 
** Started on  Wed Dec 30 23:57:02 2015 cyril puccio
** Last update Thu Dec 31 00:40:24 2015 cyril puccio
*/

#include <lapin.h>
#include <math.h>

double		vecnorm(t_bunny_position *coord0,
			t_bunny_position *coord1)
{
  double	vecl;

  vecl = sqrt(pow(coord1->x - coord0->x, 2) + pow(coord1->y - coord0->y, 2));
  return (vecl);
}
