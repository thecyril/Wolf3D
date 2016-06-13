// Jason Brillante "Damdoshi"
// Epitech 1999-2042
//
// Bibliotheque Lapin

#include		"lapin_private.h"

t_bunny_music		*bunny_load_music(const char		*file)
{
  struct bunny_music	*mus;

  if ((mus = new (std::nothrow) struct bunny_music) == NULL)
    goto Fail;
  if ((mus->music.openFromFile(file)) == false)
    goto FailStruct;

  mus->type = MUSIC;
  mus->duration = mus->music.getDuration().asSeconds();
  
  return ((t_bunny_music*)mus);

 FailStruct:
  delete mus;
 Fail:
  return (NULL);
}
