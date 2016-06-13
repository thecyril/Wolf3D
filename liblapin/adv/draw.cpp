// Jason Brillante "Damdoshi"
// Epitech 1999-2042
//
// Lapin library

#include		"lapin_private.h"

void			bunny_draw(const t_bunny_picture	*picture)
{
  struct bunny_picture	*pic = (struct bunny_picture*)picture;

  pic->texture->display();
}
