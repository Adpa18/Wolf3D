/*
** main.c for main in /home/wery_a/rendu/minilibX/FDF
**
** Made by adrien wery
** Login   <wery_a@epitech.net>
**
** Started on  Wed Nov 26 11:30:39 2014 adrien wery
** Last update Sun Dec 21 00:22:39 2014 adrien wery
*/

#include    "system.h"

int         expose(t_system *sys)
{
    mlx_put_image_to_window(sys->mlx, sys->win, sys->image.img, 0, 0);
    return (0);
}

void	my_pixel_put_to_image(char *data, unsigned int pos, int color)
{
    if (data[pos] != ((color >> 8) & 255)) {
        data[pos] = (color >> 8) & 255;
    }
    ++pos;
    if (data[pos] != ((color >> 16) & 255)) {
        data[pos] = (color >> 16) & 255;
    }
    ++pos;
    if (data[pos] != ((color >> 24) & 255)) {
        data[pos] = (color >> 24) & 255;
    }
}

int     init_mlx(t_system *sys)
{
    if ((sys->mlx = mlx_init()) == NULL) {
        return (my_error("Could not initiate MiniLibX", -1));
    }
    sys->win = mlx_new_window(sys->mlx, WIDTH, HEIGHT, "Wolf3D");
    sys->image.img = mlx_new_image(sys->mlx, WIDTH, HEIGHT);
    sys->image.data = mlx_get_data_addr(sys->image.img, &(sys->image.bpp), &(sys->image.sizeline), &(sys->image.endian));
    mlx_put_image_to_window(sys->mlx, sys->win, sys->image.img, 0, 0);
    return (0);
}
