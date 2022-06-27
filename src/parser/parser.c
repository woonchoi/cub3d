#include "parser.h"

void	get_valid_line_length(t_info *info, char *line)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	if (!line || !*line)
		return ;
	while (line[i])
	{
		if (line[i] != ' ')
		{
			len = i;
			if (len < info->m_width_offset)
				info->m_width_offset = len;
		}
		i++;
	}
	if (len > info->m_width)
		info->m_width = len;
}

void	malloc_map(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	info->m_width -= (info->m_width_offset - 3);
	info->m_height += 3;
	info->map = (char **)calloc(info->m_height, sizeof(char *));
	if (!info->map)
		print_err(MALLOC_ERR);
	while (i < info->m_height - 1)
	{
		j = 0;
		info->map[i] = (char *)malloc((info->m_width + 1) * sizeof(char));
		if (!info->map[i])
			print_err(MALLOC_ERR);
		while (j < info->m_width)
		{
			info->map[i][j] = ' ';
			j++;
		}
		info->map[i][j] = 0;
		i++;
	}
}

void	malloc_map_with_size(t_info *info)
{
	int		map_end_flag;
	t_plist	*cur;

	info->m_width = 0;
	info->m_height = 0;
	info->m_width_offset = INT_MAX;
	map_end_flag = FALSE;
	cur = info->head;
	while (cur)
	{
		if (is_line_only_space(cur->line))
			map_end_flag = TRUE;
		else if (!is_line_only_space(cur->line) && map_end_flag == TRUE)
			print_err(SPLITTED_MAP);
		else
		{
			info->m_height++;
			get_valid_line_length(info, cur->line);
		}
		cur = cur->next;
	}
	malloc_map(info);
}

void	create_map_with_list(t_info *info)
{
	t_plist	*cur;
	int		i;
	int		j;

	malloc_map_with_size(info);
	cur = info->head;
	i = 1;
	while (cur)
	{
		j = 1;
		while (j < info->m_width && cur->line[j - 1 + info->m_width_offset])
		{
			info->map[i][j] = cur->line[j - 1 + info->m_width_offset];
			j++;
		}
		cur = cur->next;
		i++;
	}
}

void	parse_map(t_info *info, int fd)
{
	char	*line;
	int		flag;

	flag = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (flag < NEED_MAP)
			set_element(info, line, &flag);
		else
			set_map_list(info, line, &flag);
		safety_free((void **)&line);
	}
	if (line && flag == ALL_EXIST)
	{
		set_map_list(info, line, &flag);
		safety_free((void **)&line);
	}
	if (flag != ALL_EXIST)
		print_err(MAP_ERR);
	create_map_with_list(info);
}
