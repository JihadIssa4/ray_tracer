#include "./minilibx-linux/mlx.h"
#include <stdlib.h>

#define WIDTH 256
#define HEIGHT 256

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
        for (int x = 0; x < WIDTH; x++)
        {
            double r = (double)x / (WIDTH - 1);
            double g = (double)y / (HEIGHT - 1);
            double b = 0.0;

            int ir = (int)(255.999 * r);
            int ig = (int)(255.999 * g);
            int ib = (int)(255.999 * b);

            int color = (ir << 16) | (ig << 8) | ib;
            *(unsigned int *)(addr + y * line_len + x * (bpp / 8)) = color;
        }
    }

    mlx_put_image_to_window(mlx, win, img, 0, 0);
    mlx_loop(mlx);
    return 0;
}
