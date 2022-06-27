#include "mlx_logic.h"

void	init_mlx(t_info *info)
{
	info->mlx_ptr = mlx_init();
	if (!info->mlx_ptr)
		print_err(MLX_ERR);
}

void	init_win(t_info *info)
{
	int	width;
	int	height;

	width = info->screen.width;
	height = info->screen.height;
	info->win_ptr = mlx_new_window(info->mlx_ptr, width, height, "cub3d");
	if (!info->win_ptr)
		print_err(WIN_ERR);
}
