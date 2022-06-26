#include <stdlib.h> 

void	safety_free(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = 0;
	}
}
