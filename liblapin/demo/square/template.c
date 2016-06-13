
#include		<lapin.h>

int			main(void)
{
  t_bunny_window	*win;
  t_bunny_picture	*pic;

  win = bunny_start(800, 600, false, "Square");
  pic = bunny_new_picture(800, 600);
  pic->clip_width = rand() % 799 + 1;
  pic->clip_height = rand() % 599 + 1;
  pic->clip_x_position = rand() % (pic->buffer.width - pic->clip_width);
  pic->clip_y_position = rand() % (pic->buffer.height - pic->clip_height);
  bunny_clear(&win->buffer, BLACK);
  bunny_clear(&pic->buffer, rand() | BLACK);
  bunny_blit(&win->buffer, pic, NULL);
  bunny_display(win);
  bunny_loop(win, 25, NULL);
  bunny_delete_clipable(pic);
  bunny_stop(win);
  return (0);
}

