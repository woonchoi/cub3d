#include "parser.h"

t_plist	*create_plist_node(char *line)
{
	t_plist	*ret;

	ret = (t_plist *)malloc(sizeof(t_plist));
	if (!ret)
		print_err(MALLOC_ERR);
	ret->line = ft_strdup(line);
	ret->next = NULL;
	return (ret);
}

void	plist_add_back(t_info *info, char *line)
{
	t_plist	*cur;

	if (!info->head)
		info->head = create_plist_node(line);
	else
	{
		cur = info->head;
		while (cur->next)
			cur = cur->next;
		cur->next = create_plist_node(line);
	}
}