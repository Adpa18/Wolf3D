/*
** trace.c for trace in /home/wery_a/rendu/minilibX/Wolf3D
**
** Made by adrien wery
** Login   <wery_a@epitech.net>
**
** Started on  Fri Dec 19 04:13:14 2014 adrien wery
** Last update Sun Dec 21 18:27:04 2014 adrien wery
*/

#include "system.h"

void		my_hook(t_system *sys)
{
    mlx_hook(sys->win, KeyPress, KeyPressMask, &move_on, sys);
    mlx_hook(sys->win, KeyRelease, KeyReleaseMask, &move_off, sys);
    mlx_loop_hook(sys->mlx, key_move, sys);
    mlx_expose_hook(sys->win, &expose, sys);
    mlx_loop(sys->mlx);
}



void             trace_back(t_system *sys)
{
    int           i;
    int           j;

    i = 0;
    j = HEIGHT * sys->image.sizeline / 2;
    while (i < HEIGHT * sys->image.sizeline / 2)
    {
        my_pixel_put_to_image(sys->image.data, i, 0xFF404000);
        my_pixel_put_to_image(sys->image.data, j, 0x00C80000);
        i += 4;
        j += 4;
    }
}

void             trace_wall(t_system *sys)
{
    int           i;
    int           k;
    int           a;
    int           set;
    int           color;

    set = sys->image.sizeline * HEIGHT / 2;
    a = -1;
    while (++a < WIDTH)
    {
        i = set + a * 4;
        k = -1;
        while (++k < HEIGHT / 2 + 1 && k < HEIGHT / (2 * sys->vecs[a].k))
        {
            color = 0xFFFFFFFF;
            my_pixel_put_to_image(sys->image.data, i, color);
            my_pixel_put_to_image(sys->image.data, set + a * 4 - sys->image.sizeline * k, color);q
            i += sys->image.sizeline;
        }
    }
}
