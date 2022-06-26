#ifndef CUB_H
# define CUB_H

# include "mlx.h"
# include "struct.h"
# include "constant.h"
# include "cub_util.h"
# include <stdlib.h> 

void	check_valid_arg(int argc, char **argv);
void    init_info(t_info *info, char *path);
int		exit_hook(t_info *info);

#endif