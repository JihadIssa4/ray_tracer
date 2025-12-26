#include "./minilibx-linux/mlx.h"
#include "ui.h"
#include "error.h"

int	ui_initMlx(ui_mlxParams_t *p, int w, int h, char *ttl)
{
    p->mlx = mlx_init();
    p->win = mlx_new_window(p->mlx, w, h, ttl);
    p->img = mlx_new_image(p->mlx, w, h);
    p->buf = mlx_get_data_addr(p->img, &p->bpp, &p->line_len, 0);
    return (p->mlx && p->img && p->buf);
}

void	ui_mlxRender(ui_mlxParams_t *p)
{
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	mlx_loop(p->mlx);
}

int	ui_buildImg(char *buf);
{
	int	y;
	int	x;
	char	*str;

	y = 0;
	while (y < height)
	{
		err_writeStdErr({"Remaining lines: ", ft_itoa(height - y), "\n"})
		write(2, "Remaining Lines: ", 17);
		char *str = ft_itoa(HEIGHT - y);
		write(2, str, ft_strlen(str));
		write(1, "\n", 1);
		x = 0;
		while (x < width)
		{
		    double r = (double)x / (WIDTH - 1);
		    double g = (double)y / (HEIGHT - 1);
		    double b = 0.0;

		    int ir = (int)(255 * r); //255.999
		    int ig = (int)(255 * g);
		    int ib = (int)(255 * b);

		    int color = (ir << 16) | (ig << 8) | ib;
		    *(unsigned int *)(addr + y * line_len + x * (bpp / 8)) = color;
		}
		y ++;
}
write(2, "Done.", 5);

}
