/*
** system.h for system in /home/wery_a/rendu/minilibX
**
** Made by adrien wery
** Login   <wery_a@epitech.net>
**
** Started on  Tue Nov 25 18:16:43 2014 adrien wery
** Last update Sun Dec 21 00:18:31 2014 adrien wery
*/

#ifndef SYSTEM_H_
# define SYSTEM_H_

#ifdef __cplusplus
extern "C"
#endif

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <X11/X.h>
#include "mlx/mlx.h"
# define WIDTH 2560
# define HEIGHT 1080
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364
# define ESCAPE 65307
# define SHIFT 65505

typedef struct	t_image
{
    void		*img;
    char		*data;
    int		    bpp;
    int		    sizeline;
    int		    endian;
}		        t_image;

typedef struct	t_vision
{
    double	k;
    double	x1;
    double	y1;
    int		x;
    int		y;
}		t_vision;

typedef struct	t_player
{
    double	x0;
    double	y0;
    double	angle;
    double	pres;
    int		len_x;
    int		len_y;
}		t_player;

typedef struct	t_move
{
    int		up;
    int		left;
    int		right;
    int		down;
    double	speed;
    int		escape;
    int		start;
}		t_move;

typedef struct	t_system
{
    void		*mlx;
    void		*win;
    char		*map;
    t_image	    image;
    t_player	*player;
    t_vision	*vecs;
    t_move	     *move;
}		         t_system;

#ifdef __cplusplus
extern "C" {
#endif
// Str
void    my_putchar(char c);
int     my_strlen(char *s);
void    my_putstr(char *s);
void	my_putnbr(int nb);
int	    my_error(char *s, char error);

// MLX
int	    init_mlx(t_system *sys);
int		expose(t_system *sys);
void	my_pixel_put_to_image(char *data, unsigned int pos, int color);

// Move
int		move(int keycode, t_system *sys);
int		move_on(int keycode, t_system *sys);
int		move_off(int keycode, t_system *sys);
int		key_move(t_system *sys);

// Init
t_player    *init_player();
t_move      *init_move();
void        init_vecs(t_vision *vecs, t_player *p, char *map);

void		trace_all(t_system *sys, t_vision *vecs, char *map);

void		my_hook(t_system *sys);
void		check_map(int file, t_player *p);
char		*wolf_tab(int file, int size);
void		trace_back(t_system *sys);
void		trace_wall(t_system *sys);
#ifdef __cplusplus
}
#endif
#endif /* !SYSTEM_H_ */
