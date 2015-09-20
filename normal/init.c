/*
** vision.c for vision in /home/wery_a/rendu/minilibX/Wolf3D
**
** Made by adrien wery
** Login   <wery_a@epitech.net>
**
** Started on  Mon Dec  8 18:49:40 2014 adrien wery
** Last update Sun Dec 21 19:06:10 2014 adrien wery
*/

#include "system.h"

t_player    *init_player()
{
    t_player *p;

    p = malloc(sizeof(t_player));
    p->x0 = 2;
    p->y0 = 2;
    p->angle = 0 * M_PI / 180;
    p->pres = 1;
    return (p);
}

t_move *init_move()
{
    t_move *move;

    move = malloc(sizeof(t_move));
    move->up = 0;
    move->left = 0;
    move->right = 0;
    move->down = 0;
    move->speed = 0.2;
    move->escape = 0;
    move->start = 0;
    return (move);
}
