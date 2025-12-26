typedef struct ui_mlxParams_s
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*buf;
	int	bpp;
	int	line_len;
}	ui_mlxParams_t;

int	ui_initMlx(mlxParams_t *params, int width, int height, char *title);

int	ui_mlxRender(mlxParams_t *params);
