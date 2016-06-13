/*
** Jason Brillante "Damdoshi"
** Hanged Bunny Studio 2014-2015
**
** Chrono
*/

#include		<stdio.h>
#include		<time.h>
#include		<lapin.h>

struct timespec		start;
struct timespec		tspec;
uint64_t		start_cnt;
uint64_t		tspec_cnt;			
int			cnt;

static t_bunny_response	loop(void		*data)
{
  t_bunny_window	*win = data;

  bunny_clear(&win->buffer, rand() | BLACK);
  bunny_display(win);
  clock_gettime(CLOCK_MONOTONIC, &tspec);
  start_cnt = start.tv_sec * 1000 * 1000 * 1000 + start.tv_nsec;
  tspec_cnt = tspec.tv_sec * 1000 * 1000 * 1000 + tspec.tv_nsec;
  if (tspec_cnt - start_cnt > 1000 * 1000 * 1000)
    {
      printf("%lu %d\n", tspec_cnt - start_cnt, cnt);
      cnt = 0;
      clock_gettime(CLOCK_MONOTONIC, &start);
      clock_gettime(CLOCK_MONOTONIC, &tspec);
    }
  else
    cnt += 1;
  return (GO_ON);
}

int			main(void)
{
  t_bunny_window	*win = bunny_start(800, 600, false, "");

  bunny_set_loop_main_function(loop);
  bunny_loop(win, 42, win);
  bunny_stop(win);
  return (0);
}
