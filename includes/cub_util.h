#ifndef CUB_UTIL_H
# define CUB_UTIL_H

# include "struct.h"

void	print_err(char *err_string);
void	open_err(char *path);
void	safety_free(void **ptr);

void	print_doublearray_map(t_info *info);

#endif