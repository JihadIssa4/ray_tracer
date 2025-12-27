#include "ui.h"
#include "error.h"



#include <unistd.h>
#include "./minilibx-linux/mlx.h"

int main(void)
{
    ui_mlxParams_t mlx_params;

    if (ui_initMlx(&mlx_params, 256, 256, "MiniRT"))
        return err_msgReturnOne("MLX init failed");

    mlx_loop(mlx_params.mlx);
}
