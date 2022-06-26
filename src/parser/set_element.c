#include "parser.h"

void	set_element(char *line, int *flag)
{
	char	*path;

	path = 0;
	if (is_line_only_space(line))
		return ;
	else if (check_arg("NO", line, &path))
		set_texture(flag, NO_EXIST);
	else if (check_arg("SO", line, &path))
		set_texture(flag, SO_EXIST);
	else if (check_arg("WE", line, &path))
		set_texture(flag, WE_EXIST);
	else if (check_arg("EA", line, &path))
		set_texture(flag, EA_EXIST);
	else if (check_arg("F", line, &path))
		set_color(flag, F_EXIST);
	else if (check_arg("C", line, &path))
		set_color(flag, C_EXIST);
	else
		print_err(ELEMENT_ERR);
}