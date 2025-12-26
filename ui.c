#include "./minilibx-linux/mlx.h"

int	ui_initMlx(mlxParams_t *p, int w, int h, char *ttl)
{
    p->mlx = mlx_init();
    p->win = mlx_new_window(p->mlx, width, height, ttl);
    p->img = mlx_new_image(mlx, width, height);
    p->buf = mlx_get_data_addr(p->img, &p->bpp, &p->line_len, &p->endian);
    return (p->mlx && p->img && p->buf);
}

void	ui_mlxRender(mlxParams_t *p)
{
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	mlx_loop(p->mlx);
}
