// Jason Brillante "Damdoshi"
// Epitech 1999-2042
//
// Bibliotheque Lapin

#include		"lapin_private.h"

void			bunny_delete_ini(t_bunny_ini	*ini)
{
  bpt::Ini		*in = (bpt::Ini*)ini;

  delete in;
}

