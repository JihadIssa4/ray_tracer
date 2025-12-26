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
}	ui_mlxParams_t;

int	ui_initMlx(ui_mlxParams_t *params, int width, int height, char *title);

void	ui_mlxRender(ui_mlxParams_t *params);

void	ui_buildImg(char *buf, int height, int weight);
#endif
