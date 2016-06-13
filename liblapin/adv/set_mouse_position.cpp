// Jason Brillante "Damdoshi"
// Epitech 1999-2042
//
// Bibliotheque Lapin

#include			"lapin_private.h"

void				bunny_set_mouse_position_window(const t_bunny_window	*_win,
								int			x,
								int			y)
{
  const struct bunny_window	*win = (const struct bunny_window*)_win;
  
  sf::Mouse::setPosition(sf::Vector2i(x, y), *win->window);
  gl_mouse.x = x;
  gl_mouse.y = y;
}

void				bunny_set_mouse_position(int				x,
							 int				y)
{
  sf::Mouse::setPosition(sf::Vector2i(x, y));
  gl_mouse.x = x;
  gl_mouse.y = y;
}

