/*
** struc.h for struc in /home/puccio_c/rendu/PSU_2015_my_printf
** 
** Made by cyril puccio
** Login   <puccio_c@epitech.net>
** 
** Started on  Tue Nov 10 13:05:09 2015 cyril puccio
** Last update Sun Feb 28 12:59:37 2016 cyril puccio
*/

#ifndef		_STRUCT_H
# define	_STRUCT_H

#include <stdarg.h>

typedef struct		s_var
{
  int			posx;
  int			posy;
  double		chpv;
  double		angl;
  double		stepang;
  int			stepdir;
  int			dmcb;
  int			res;
  int			cote;
  int                   mapw;
  int                   maph;
  int			footstep;
  int			posckx;
  int			poscky;
  double		a;
  double		a_rad;
  t_bunny_window        *win;
  t_bunny_pixelarray    *pix;
  t_bunny_pixelarray    *pix2;
  t_bunny_position      start;
  t_bunny_ini		*ini;
  int			Wscreen;
  int			i;
}			t_var;

void    my_putchar(char c);

void    my_put_nbr(int  nb);

int     my_putstr(char *str);

int     my_strlen(char *str);

int     my_strcmp(char *s1, char *s2);

int     my_str_ispprintable(char *str);

int     my_ls(char *dir);

char    *my_strlowcase(char *str);

void    my_putnbr_base(int nb, char *base);

void    my_printf(char *str, ...);

void    structure(char *str, va_list ap);

void    put_str(va_list list);

void    put_nbr(va_list list);

void    put_char(va_list list);

void    put_base8(va_list list);

void    put_base16(va_list list);

void    put_basemaj16(va_list list);

void    put_base2(va_list);

void    put_unbr(va_list);

void    put_phex(va_list);

int	my_getnbr(const char *str);

double  my_atof(const char *str);

t_bunny_response        mainloop(t_var *var);

void                    fillpixel(t_bunny_pixelarray *pix,
                                  int desx,
                                  int desy,
                                  t_color color,
                                  t_var *var);

t_bunny_response	key(t_bunny_event_state      state,
                               t_bunny_keysym           button,
                               void                     *data);

int		       	wolf(char *map);

bool			colide(t_bunny_position *newpos, t_var *var);

void			fill_struct(t_var *var, t_bunny_ini *ini);

void			tekpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 t_color *color);

int			wall_color(int cote);

int			detcote(int x, int y, t_var *var);

void                    line_tracer(int hwall, double angle,
				    double chpv,
                                    t_bunny_pixelarray *pix,
				    t_var *var);

const char		*pos(int x, int y, t_var *var);

double			vecnorm(t_bunny_position *coord0,
				t_bunny_position *coord1);

void			go(t_bunny_position *curpos,
			   double angle,
			   t_bunny_position *newpos,
			   int move);

void			raychecker(t_var *var, int mapw, int maph,
				   t_bunny_pixelarray *pix);

void			ampl_checker(t_var *var, int mapw, int maph,
				     t_bunny_pixelarray *pix);

int			wallh(int dist, double angl, t_var **var);

bool			touch(int rayamp, bool hit, t_var *var,
			      t_bunny_pixelarray *pix);

bool			up(t_bunny_position pos, t_var *var,
			   t_bunny_position newpos);

bool			down(t_bunny_position pos, t_var *var,
			     t_bunny_position newpos);

bool			left(t_var *var);

bool                    right(t_var *var);

#endif	/* _STRUCT_ */
