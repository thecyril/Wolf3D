// Jason Brillante "Damdoshi"
// Epitech 1999-2042
//
// Lapin library

#include		"lapin_private.h"

void			bunny_display(const t_bunny_window	*pic)
{
  struct bunny_window	*win = (struct bunny_window*)pic;

  win->window->display();
}
