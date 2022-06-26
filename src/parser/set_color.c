#include "parser.h"

void	set_color(int *flag, int now_flag)
{
	if (*flag & now_flag)
		print_err(MAP_ERR);
	*flag |= now_flag;
}
