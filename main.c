#include "./minilibx-linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

#define WIDTH 256
#define HEIGHT 256

#include <stdio.h>

int main(void)
{
    void *mlx;
    void *win;
    void *img;
    char *addr;
    int bpp, line_len, endian;

    mlx = mlx_init();
    win = mlx_new_window(mlx, WIDTH, HEIGHT, "Gradient");
    img = mlx_new_image(mlx, WIDTH, HEIGHT);
    addr = mlx_get_data_addr(img, &bpp, &line_len, &endian);

    for (int y = 0; y < HEIGHT; y++)
    {
	write(2, "Remaining Lines: ", 17);
        char *str = ft_itoa(HEIGHT - y);
        write(2, str, ft_strlen(str));
	write(1, "\n", 1);

        for (int x = 0; x < WIDTH; x++)
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
    }
    write(2, "Done.", 5);

    mlx_put_image_to_window(mlx, win, img, 0, 0);
    mlx_loop(mlx);
    return 0;
}
