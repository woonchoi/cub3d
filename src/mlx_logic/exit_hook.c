#include "mlx_logic.h"

int	exit_hook(t_info *info)
{
	mlx_destroy_window(info->mlx_ptr, info->win_ptr);
	exit(0);
}
