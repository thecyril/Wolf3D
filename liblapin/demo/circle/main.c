
#include		<math.h>
#include		<alloca.h>
#include		<time.h>
#include		<stdlib.h>
#include		"lapin.h"

t_bunny_response	key(t_bunny_event_state		state,
			    t_bunny_keysym		sym,
			    void			*data)
{
  (void)state; (void)data;
  if (sym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

int			main(void)
{
  t_bunny_window	*win = bunny_start(800, 400, false, "");
  t_bunny_position	pos[2];
  unsigned int		col[2] = {RED, RED};
  
  srand(time(NULL));
  bunny_set_key_response(key);
  bunny_clear(&win->buffer, BLACK);

  pos[0].x = 0;
  pos[0].y = win->buffer.height / 2.0;  
  pos[1].x = win->buffer.width;
  pos[1].y = win->buffer.height / 2.0;
  bunny_set_line(&win->buffer, &pos[0], &col[0]);

  pos[0].x = win->buffer.width / 2;
  pos[0].y = 0;
  pos[1].x = win->buffer.width / 2;
  pos[1].y = win->buffer.height;
  bunny_set_line(&win->buffer, &pos[0], &col[0]);

  pos[0].x = win->buffer.width / 2;
  pos[0].y = win->buffer.height / 2;
  pos[1].x = win->buffer.width * 0.2;
  pos[1].y = win->buffer.height * 0.2;
  bunny_set_circle(&win->buffer, pos[0], pos[1], ALPHA(col[0], 32));

  bunny_display(win);
  bunny_loop(win, 20, NULL);
  bunny_stop(win);
  return (0);
}

