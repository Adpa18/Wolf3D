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
    sys.cuda = (t_cuda *)malloc(sizeof(t_cuda));
    cudaMalloc((void **)&(sys.cuda->vecs), sizeof(t_vision) * WIDTH);
    cudaMalloc((void **)&(sys.cuda->player), sizeof(t_player));
    cudaMalloc((void **)&(sys.cuda->map), (sys.player->len_x + 1) * (sys.player->len_y + 1));
    cudaMalloc((void **)&(sys.cuda->data), HEIGHT * sys.image.sizeline);
    cudaMemcpy(sys.cuda->map, sys.map, (sys.player->len_x + 1) * (sys.player->len_y + 1), cudaMemcpyHostToDevice);
    my_hook(&sys);
    return (0);
}
