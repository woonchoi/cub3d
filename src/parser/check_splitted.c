#include "parser.h"

int	**malloc_visited_array(t_info *info)
{
	int	i;
	int	**ret;

	i = 0;
	ret = (int **)calloc(sizeof(int *), info->m_height + 1);
	if (!ret)
		print_err(MALLOC_ERR);
	while (i < info->m_height)
	{
		ret[i] = (int *)calloc(sizeof(int), info->m_width);
		if (!ret[i])
			print_err(MALLOC_ERR);
		i++;
	}
	return (ret);
}

// need refactoring because set_dxdy and using stack with recursive is too heavy
int	recursive_dfs(t_info *info, int ***visited, int x, int y)
{
	int	dx[4];
	int	dy[4];
	int	i;
	int count;

	set_dxdy(dx, dy);
	i = 0;
	count = 0;
	while (i < 4)
	{
		if (!(*visited)[y + dy[i]][x + dx[i]])
		{
			if (ft_strchr("01NSEW", info->map[y + dy[i]][x + dx[i]]))
			{
				(*visited)[y + dy[i]][x + dx[i]] = TRUE;
				count += 1;
				count += recursive_dfs(info, visited, x + dx[i], y + dy[i]);
			}
		}
		i++;
	}
	return (count);
}

int	check_splitted_dfs(t_info *info, int x, int y)
{
	int	**visited;
	int	count;
	int	i;

	visited = malloc_visited_array(info);
	count = recursive_dfs(info, &visited, x, y);
	i = 0;
	while (visited[i])
	{
		safety_free((void **)&(visited[i]));
		i++;
	}
	free(visited);
	return (count);
}

void	check_splitted(t_info *info, int count)
{
	int	x;
	int	y;
	int	check;

	y = 1;
	check = FALSE;
	while (y < info->m_height - 1 && !check)
	{
		x = 1;
		while (x < info->m_width - 1 && !check)
		{
			if (ft_strchr("01NSEW", info->map[y][x]))
				check = check_splitted_dfs(info, x, y);
			x++;
		}
		y++;
	}
	if (check != count)
		print_err(SPLITTED_MAP);
}
