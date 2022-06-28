#ifndef CUB_H
# define CUB_H

# include "mlx.h"
# include "struct.h"
# include "constant.h"
# include "cub_util.h"
# include <math.h>
# include <stdlib.h> 

void	check_valid_arg(int argc, char **argv);
void    init_info(t_info *info, char *path);
int		exit_hook(t_info *info);
int		key_press(int key, t_info *info);
int		key_release(int key, t_info *info);
void	key_update(t_info *info, t_raycast_util *r);

#endif