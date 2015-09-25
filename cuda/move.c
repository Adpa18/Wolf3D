/*
** main.c for main in /home/wery_a/rendu/minilibX/FDF
**
** Made by adrien wery
** Login   <wery_a@epitech.net>
**
** Started on  Wed Nov 26 11:30:39 2014 adrien wery
** Last update Sun Dec 21 00:22:39 2014 adrien wery
*/

#include "system.h"

int		move_on(int keycode, t_system *sys)
{
    if (keycode == ESCAPE)
    {
        sys->move->escape = 1;
        exit(EXIT_SUCCESS);
    }
    if (keycode == SHIFT)
        sys->move->speed = 0.5;
    if (keycode == LEFT)
        sys->move->left = 1;
    if (keycode == RIGHT)
        sys->move->right = 1;
    if (keycode == UP)
        sys->move->up = 1;
    if (keycode == DOWN)
        sys->move->down = 1;
    return (0);
}

int		move_off(int keycode, t_system *sys)
{
    if (keycode == ESCAPE)
    {
        sys->move->escape = 0;
        exit(EXIT_SUCCESS);
    }
    if (keycode == SHIFT)
        sys->move->speed = 0.1;
    if (keycode == LEFT)
        sys->move->left = 0;
    if (keycode == RIGHT)
        sys->move->right = 0;
    if (keycode == UP)
        sys->move->up = 0;
    if (keycode == DOWN)
        sys->move->down = 0;
    return (0);
}

int		key_move(t_system *sys)
{
    if (sys->move->up == 1)
    {
        sys->player->x0 += sys->move->speed * cos(sys->player->angle);
        sys->player->y0 += sys->move->speed * sin(sys->player->angle);
    }
    if (sys->move->down == 1)
    {
        sys->player->x0 -= sys->move->speed * cos(sys->player->angle);
        sys->player->y0 -= sys->move->speed * sin(sys->player->angle);
    }
    if (sys->move->left == 1)
        sys->player->angle += sys->move->speed;
    if (sys->move->right == 1)
        sys->player->angle -= sys->move->speed;
    if (sys->move->up == 1 || sys->move->left == 1 ||sys->move->right == 1 || sys->move->down == 1 || sys->move->start == 0)
    {
        sys->move->start = 1;
        calc_window(sys);
        // init_vecs(sys->vecs, sys->player, sys->map);
        // trace_back(sys);
        trace_wall(sys);
        mlx_put_image_to_window(sys->mlx, sys->win, sys->image.img, 0, 0);
    }
    return (0);
}
