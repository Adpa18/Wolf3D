/*
** main.c for main in /home/wery_a/rendu/minilibX/FDF
**
** Made by adrien wery
** Login   <wery_a@epitech.net>
**
** Started on  Wed Nov 26 11:30:39 2014 adrien wery
** Last update Sun Dec 21 00:22:39 2014 adrien wery
*/

#include        "system.h"

__global__ void		init_vecs_cuda(t_vision *vecs, t_player *p, char *map)
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
    i = blockIdx.x;
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

int		       main()
{
    t_system    sys;
    int         fd;

    init_mlx(&sys);
    sys.player = init_player();
    sys.move = init_move();
    if ((fd = open("./laby", O_RDONLY)) == 1) {
        my_error("Error to open the map", 1);
    }
    check_map(open("./laby", O_RDONLY), sys.player);
    sys.map = wolf_tab(fd, (sys.player->len_x + 1) * (sys.player->len_y + 1));
    sys.vecs = (t_vision *)malloc(sizeof(t_vision) * WIDTH);

    t_vision *vecs;
    t_player *player;
    char *map;

    cudaMalloc((void **)&vecs, sizeof(t_vision) * WIDTH);
    cudaMalloc((void **)&player, sizeof(t_player));
    cudaMalloc((void **)&map, (sys.player->len_x + 1) * (sys.player->len_y + 1));

    cudaMemcpy(player, sys.player, sizeof(t_player), cudaMemcpyHostToDevice);
    cudaMemcpy(map, sys.map, (sys.player->len_x + 1) * (sys.player->len_y + 1), cudaMemcpyHostToDevice);

    init_vecs_cuda<<<WIDTH,1>>>(vecs, player, map);

    cudaMemcpy(sys.vecs, vecs, sizeof(t_vision) * WIDTH, cudaMemcpyDeviceToHost);

    // int i = -1;
    // while (++i < WIDTH) {
    //     printf("k = %f\nx1 = %f\ny1 = %f\nx = %d\ny = %d\n", sys.vecs[i].k, sys.vecs[i].x1, sys.vecs[i].y1, sys.vecs[i].x, sys.vecs[i].y);
    // }
    my_hook(&sys);
    return (0);
}
