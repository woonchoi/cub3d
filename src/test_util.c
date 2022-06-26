#include <stdio.h>
#include "struct.h"

void	print_doublearray_map(t_info *info)
{
	int i;

	i = 0;
	while (i < info->m_width + 2)
	{
		printf("-");
		i++;
	}
	printf("\n");
	i = 0;
	while (info->map[i])
	{
		printf("|%s|\n", info->map[i]);
		i++;
	}
	i = 0;
	while (i < info->m_width + 2)
	{
		printf("-");
		i++;
	}
	printf("\n");
}