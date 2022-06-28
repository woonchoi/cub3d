#include "mlx_logic.h"
#include <stdio.h>

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
