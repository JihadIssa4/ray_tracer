#include "./minilibx-linux/mlx.h"

void	*ui_init(char *windowTitle, int height, int width)
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, width, height, windowTitle);
	return (mlx_new_image(mlx, width, height));
}

char	*ui_getImgBuf(char *img)
{
	return (mlx_get_data_addr(img, 0, 0, 0));
}

