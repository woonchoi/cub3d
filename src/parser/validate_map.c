#include "parser.h"

void	validate_map(t_info *info)
{
	int	count;

	check_wall(info);
	count = count_element(info);
	check_splitted(info, count);
}
