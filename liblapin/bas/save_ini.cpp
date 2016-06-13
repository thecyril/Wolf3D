// Jason Brillante "Damdoshi"
// Epitech 1999-2042
//
// Bibliotheque Lapin

#include		"lapin_private.h"

bool			bunny_save_ini(t_bunny_ini		*_ini,
				       const char		*file)
{
  bpt::Ini		*ini = (bpt::Ini*)_ini;
  std::string		fil = file;

  return (ini->Save(fil));
}
