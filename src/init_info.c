#include "parser.h"
#include "mlx_logic.h"

void	init_map(t_info *info, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd <= 0)
		open_err(path);
	parse_map(info, fd);
	free_parse_list(info);
	print_doublearray_map(info);
	validate_map(info);
}

void    init_info(t_info *info, char *path)
{
	info->head = NULL;
	init_map(info, path);
	init_mlx(info);
}
