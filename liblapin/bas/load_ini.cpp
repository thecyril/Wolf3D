// Jason Brillante "Damdoshi"
// Epitech 1999-2042
//
// Bibliotheque Lapin

#include		<string.h>
#include		"lapin_private.h"

extern char		*ini_last_error;

t_bunny_ini		*bunny_load_ini(const char		*file)
{
  bpt::Ini		*ini = new (std::nothrow) bpt::Ini;

  if (ini == NULL)
    return (NULL);
  std::string		fil = file;

  try
    {
      if (ini->Load(fil) == false)
	{
	  if (ini_last_error != NULL)
	    free(ini_last_error);
	  ini_last_error = strdup(ini->errmsg.c_str());
	  delete ini;
	  return (NULL);
	}
    }
  catch (...)
    {
      return (NULL);
    }
  return ((t_bunny_ini*)ini);
}
