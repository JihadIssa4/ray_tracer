#ifndef UI_H
#define UI_H

typedef struct ui_mlxParams_s
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*buf;
	int	bpp;
	int	line_len;
	int	endian;
	int	width;
	int	height;
}	ui_mlxParams_t;

int	ui_initMlx(ui_mlxParams_t *params, int width, int height, char *title);

void	ui_mlxRender(ui_mlxParams_t *params);

void	ui_buildImg(ui_mlxParams_t* params);
#endif
