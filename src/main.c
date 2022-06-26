#include "cub.h"

int main(int argc, char **argv)
{
	t_info	info;

	check_valid_arg(argc, argv);
	init_info(&info, argv[1]);
	mlx_hook(info.win_ptr, 17, 0, &exit_hook, &info);
	mlx_loop(info.mlx_ptr);
	exit(0);
}
