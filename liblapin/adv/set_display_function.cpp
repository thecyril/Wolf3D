// Jason Brillante "Damdoshi"
// Epitech 1999-2042
//
// Lapin library

#include		"lapin_private.h"

void			bunny_set_display_function(t_bunny_display	display)
{
  gl_callback.display = display;
}

