/*
** my.h for my.h in /home/puccio_c/rendu/Piscine_C_J09/include
** 
** Made by cyril puccio
** Login   <puccio_c@epitech.net>
** 
** Started on  Fri Oct  9 15:26:13 2015 cyril puccio
** Last update Sun Jan  3 18:23:08 2016 cyril puccio
*/

#ifndef _MY_LIB_
#define _MY_LIB_

void	my_putchar(char c);

void	my_put_nbr(int	nb);

int	my_putstr(char *str);

int	my_strlen(char *str);

int	my_strcmp(char *s1, char *s2);

int	my_str_ispprintable(char *str);

int     my_ls(char *dir);

void    sort_list(t_list **list);

void    my_show_list(t_list *list);

void    my_put_in_list(t_list **list, char *name);

char	*my_strlowcase(char *str);

void    my_putnbr_base(int nb, char *base);

void	my_printf(char *str, ...);

void	init(t_struct *ptr);

void	structure(char *str, va_list ap);

void	put_str(va_list list);

void	put_nbr(va_list list);

void	put_char(va_list list);

void	put_base8(va_list list);

void	put_base16(va_list list);

void	put_basemaj16(va_list list);

void	put_base2(va_list);

void	put_unbr(va_list);

void	put_phex(va_list);

double	my_atof(char *str);

t_bunny_response	mainloop(t_var *var);

void                    fillpixel(t_bunny_pixelarray *pix,
				  int desx,
                                  int desy,
				  t_color color,
				  t_var *var);

#endif
