

#include		<lapin.h>
#include		<stdlib.h>
#include		<assert.h>

t_bunny_window		*win;
t_bunny_pixelarray	*pix;

t_bunny_response	key(t_bunny_event_state		s,
			    t_bunny_keysym		sym,
			    void			*a)
{
  (void)s; (void)a;
  if (sym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_bunny_response	loop(void			*a)
{
  int			*p = pix->pixels;
  int			i;

  (void)a;
  for (i = 0; i < 1000; ++i)
    p[rand() % (win->buffer.width * win->buffer.height)] = rand() | BLACK;
  bunny_save_pixelarray(pix, "out.png");
  bunny_blit(&win->buffer, &pix->clipable, NULL);
  bunny_display(win);
  return (GO_ON);
}

int			main(void)
{
  int			*p;
  int			l;
  int			i;

  assert(win = bunny_start(640, 480, false, "Little Resolution"));
  assert(pix = bunny_new_pixelarray(win->buffer.width, win->buffer.height));
  p = pix->pixels;
  for (i = 0, l = win->buffer.width * win->buffer.height; i < l; ++i)
    p[i] = BLACK;
  bunny_set_key_response(key);
  bunny_set_loop_main_function(loop);
  bunny_loop(win, 25, NULL);
  bunny_delete_clipable(&pix->clipable);
  bunny_stop(win);
  return (EXIT_SUCCESS);
}

