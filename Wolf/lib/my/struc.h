/*
** struc.h for struc in /home/puccio_c/rendu/PSU_2015_my_printf
** 
** Made by cyril puccio
** Login   <puccio_c@epitech.net>
** 
** Started on  Tue Nov 10 13:05:09 2015 cyril puccio
** Last update Mon Nov 16 21:00:48 2015 cyril puccio
*/

#ifndef		_STRUCT_H
# define	_STRUCT_H

# include	<stdarg.h>

typedef struct  s_struct
{
  char          c;
  void          (*ptr)(va_list);
}		t_struct;

void		put_str(va_list);
void		put_nbr(va_list);
void		put_char(va_list);
void		put_base8(va_list);
void		put_base16(va_list);
void		put_basemaj16(va_list);
void		put_base2(va_list);
void		put_unbr(va_list);
void		put_phex(va_list);

#endif	/* _STRUCT_ */
