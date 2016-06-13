// Jason Brillante "Damdoshi"
// Epitech 1999-2042
//
// Bibliotheque Lapin

#include		"lapin_private.h"

t_bunny_ini		*bunny_new_ini(void)
{
  bpt::Ini		*ini = new (std::nothrow) bpt::Ini;

  if (ini == NULL)
    return (NULL);
  return ((t_bunny_ini*)ini);
}

