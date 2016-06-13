/*
** my_effect_test.c for test in /home/le-mai_s/Downloads/liblapin1.7/demo/effect
**
** Made by Sébastien Le Maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Thu Feb  4 15:08:56 2016 Sébastien Le Maire
** Last update Thu Feb  4 17:24:31 2016 Sébastien Le Maire
*/

#include		<math.h>
#include		<stdlib.h>
#include		<unistd.h>
#include		<stdio.h>
#include		<string.h>
#include		"../include/lapin.h"

/*
** Piano (notes) :
*/
typedef enum	e_note
  {
		LA = 0,
		LA_D,
		SI_B = LA_D,
		SI,
		DO,
		DO_D,
		RE_B = DO_D,
		RE,
		RE_D,
		MI_B = RE_D,
		MI,
		FA,
		FA_D,
		SOL_B = FA_D,
		SOL,
		SOL_D,
		LA_B = SOL_D
  }		t_note;

# define        HALF_TONE	(1.05946)

double		my_piano(t_note const note, int oct)
{
  double	basic_la = 440;
  double	mv_oct = (oct >= 0) ? (double)2 : (double)0.5;
  int		i;

  oct = (oct >= 0) ? oct : -oct;
  for (i = 0; i < oct; ++i)
    basic_la *= mv_oct;
  for (i = 0; i < (int)note; ++i)
    basic_la *= HALF_TONE;
  if (note >= DO)
    basic_la /= 2;
  return (basic_la / 220);
}

/*
** Macro and struct effect.c lapin
*/

# define		MINUTE		(60.0 * 1000.0)
# define		TEMPO		120.0

# define		RONDE		(BLANCHE * 2)
# define		BLANCHE		(NOIRE * 2)
# define		NOIREP		((double)NOIRE * 1.5)
# define		NOIRE		(MINUTE / TEMPO)
# define		CROCHE		(NOIRE / 2)
# define		DCROCHE		(CROCHE / 2)

typedef struct		s_midi_like
{
  double		pitch;		// ratio
  unsigned int		length;		// ms
}			t_midi_like;

/*
** Programme :
*/

static void		play_Ode_a_la_joie(t_bunny_effect	*m)
{
  int			current;
  t_midi_like		song[200] =
    {
      ///
      {my_piano(MI, 0), NOIRE},
      {my_piano(MI, 0), NOIRE},
      {my_piano(FA, 0), NOIRE},
      {my_piano(SOL, 0), NOIRE},
      {my_piano(SOL, 0), NOIRE},
      {my_piano(FA, 0), NOIRE},
      {my_piano(MI, 0), NOIRE},
      {my_piano(RE, 0), NOIRE},
      {my_piano(DO, 0), NOIRE},
      {my_piano(DO, 0), NOIRE},
      {my_piano(RE, 0), NOIRE},
      {my_piano(MI, 0), NOIRE},
      {my_piano(MI, 0), NOIREP},
      {my_piano(RE, 0), CROCHE},
      {my_piano(RE, 0), BLANCHE},
      ///
      {my_piano(MI, 0), NOIRE},
      {my_piano(MI, 0), NOIRE},
      {my_piano(FA, 0), NOIRE},
      {my_piano(SOL, 0), NOIRE},
      {my_piano(SOL, 0), NOIRE},
      {my_piano(FA, 0), NOIRE},
      {my_piano(MI, 0), NOIRE},
      {my_piano(RE, 0), NOIRE},
      {my_piano(DO, 0), NOIRE},
      {my_piano(DO, 0), NOIRE},
      {my_piano(RE, 0), NOIRE},
      {my_piano(MI, 0), NOIRE},
      {my_piano(RE, 0), NOIREP},
      {my_piano(DO, 0), CROCHE},
      {my_piano(DO, 0), NOIRE},

      {-1, 0}
    };

  for (current = 0; song[current].pitch >= 0; ++current)
    {
      bunny_sound_stop(&m->sound);
      bunny_sound_pitch(&m->sound, song[current].pitch);
      bunny_sound_play(&m->sound);
      usleep(song[current].length * 1000);
    }
}

static void		play_lettre_a_elise(t_bunny_effect	*m)
{
  int			current;
  t_midi_like		song[200] =
    {
      ///
      {my_piano(MI, 1), CROCHE},
      {my_piano(MI_B, 1), CROCHE},
      {my_piano(MI, 1), CROCHE},
      {my_piano(MI_B, 1), CROCHE},
      {my_piano(MI, 1), CROCHE},
      {my_piano(SI, 0), CROCHE},
      {my_piano(RE, 1), CROCHE},
      {my_piano(DO, 1), CROCHE},
      {my_piano(LA, 0), NOIREP},
      ///
      {my_piano(DO, 0), CROCHE},
      {my_piano(MI, 0), CROCHE},
      {my_piano(LA, 0), CROCHE},
      {my_piano(SI, 0), NOIREP},
      ///
      {my_piano(MI, 0), CROCHE},
      {my_piano(SOL_D, 0), CROCHE},
      {my_piano(SI, 0), CROCHE},
      {my_piano(DO, 1), NOIREP},
      ///
      {my_piano(MI, 1), CROCHE},
      {my_piano(MI_B, 1), CROCHE},
      {my_piano(MI, 1), CROCHE},
      {my_piano(MI_B, 1), CROCHE},
      {my_piano(MI, 1), CROCHE},
      {my_piano(SI, 0), CROCHE},
      {my_piano(RE, 1), CROCHE},
      {my_piano(DO, 1), CROCHE},
      {my_piano(LA, 0), NOIREP},
      ///
      {my_piano(DO, 0), CROCHE},
      {my_piano(MI, 0), CROCHE},
      {my_piano(LA, 0), CROCHE},
      {my_piano(SI, 0), NOIREP},
      ///
      {my_piano(MI, 0), CROCHE},
      {my_piano(DO, 1), CROCHE},
      {my_piano(SI, 0), CROCHE},
      {my_piano(LA, 0), NOIREP},
      ///
      {-1, 0}
    };

  for (current = 0; song[current].pitch >= 0; ++current)
    {
      bunny_sound_stop(&m->sound);
      bunny_sound_pitch(&m->sound, song[current].pitch);
      bunny_sound_play(&m->sound);
      usleep(song[current].length * 1000);
    }
}

int			main(void)
{
  t_bunny_effect	*music;
  int			val[8] = {10000, 7000, 4000, 1000, -2000, -5000, -8000, -11000};
  size_t		i;

  if (!(music = bunny_new_effect(2)))
    return (EXIT_FAILURE);
  for (i = 0; i < music->sample_per_second * (music->duration - 1); ++i)
    music->sample[i] = val[(i / 25) % 8] + val[(i / 100) % 8];
  for (; i < music->sample_per_second * music->duration; ++i)
    music->sample[i] = 0;
  if (bunny_compute_effect(music) == false)
    return (EXIT_FAILURE);
  bunny_sound_loop(&music->sound, false);
  bunny_sound_volume(&music->sound, 40);
  play_lettre_a_elise(music);
  sleep(1);
  play_Ode_a_la_joie(music);
  bunny_delete_sound(&music->sound);
  return (0);
}
