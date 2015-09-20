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

void		init_vecs(t_vision *vecs, t_player *p, char *map)
{
    int		i;
    double	x1;
    double	y1;
    double cos_angle;
    double sin_angle;

    i = 0;
    x1 = p->pres / 2;
    if (p->angle / 180 * M_PI < 0) {
        p->angle = (360 + p->angle / 180 * M_PI) / M_PI * 180;
    }
    cos_angle = cos(p->angle);
    sin_angle = sin(p->angle);
    i = -1;
    while (++i < WIDTH)
    {
        y1 = p->pres * ((HEIGHT / 2) - i) / HEIGHT;
        vecs[i].x1 = fabs(x1 * cos_angle - y1 * sin_angle + p->x0);
        vecs[i].y1 = fabs(x1 * sin_angle + y1 * cos_angle + p->y0);
        vecs[i].k = 0.001;
        vecs[i].x = fabs(p->x0 + vecs[i].k * (vecs[i].x1 - p->x0));
        vecs[i].y = fabs(p->y0 + vecs[i].k * (vecs[i].y1 - p->y0));
        while (map[vecs[i].x + vecs[i].y * p->len_x] != '1')
        {
            vecs[i].x = fabs(p->x0 + vecs[i].k * (vecs[i].x1 - p->x0));
            vecs[i].y = fabs(p->y0 + vecs[i].k * (vecs[i].y1 - p->y0));
            vecs[i].k += 0.001;
        }
    }
}

char            *wolf_tab(int file, int size)
{
    int           a;
    int		n;
    char          *buff;
    char		*tab;

    buff = malloc(size * sizeof(char));
    tab = malloc(size * sizeof(char));
    if (read(file, buff, size) == 0)
        my_error("Read Failled !!!", 1);
    a = 0;
    n = 0;
    while (a != size)
        if (buff[n++] != 10)
            tab[a++] = buff[n - 1];
    tab[a - 1] = '\0';
    close(file);
    free(buff);
    a = 0;
    while (tab[a])
    {
        if (tab[a] != '1' && tab[a] != '0')
        my_error("Map Error, only 0 or 1", 1);
        a += 1;
    }
    return (tab);
}

void		check_map(int file, t_player *p)
{
    char		*buff;
    int		a;
    int		i;

    i = 0;
    p->len_x = 0;
    p->len_y = 0;
    buff = malloc(4096);
    if ((a = read(file, buff, 4096)) == 0)
    my_error("Read Failled !!!", 1);
    while (i != a - p->len_y)
    {
        p->len_x = 0;
        while (buff[i++] != 10)
        p->len_x += 1;
        p->len_y += 1;
        i += 1;
    }
    p->len_x += 1;
    p->len_y += 1;
    close(file);
    free(buff);
}
