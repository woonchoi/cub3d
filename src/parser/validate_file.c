#include "parser.h"

int	check_valid_filename(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 5)
		return (TRUE);
	if (ft_strncmp((path + len - 4), ".cub", 4))
		return (TRUE);
	return (FALSE);
}

void	check_valid_arg(int argc, char **argv)
{
	if (argc != 2)
		print_err(ARG_ERR);
	if (check_valid_filename(argv[1]))
		print_err(NAME_ERR);
}
