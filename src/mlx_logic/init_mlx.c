#include "mlx_logic.h"

void	init_mlx(t_info *info)
{
	info->mlx_ptr = mlx_init();
	if (!info->mlx_ptr)
		print_err(MLX_ERR);
	info->win_ptr = mlx_new_window(info->mlx_ptr, 1600, 900, "cub3d");
	if (!info->win_ptr)
		print_err(WIN_ERR);
}
