/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:52:27 by jasong            #+#    #+#             */
/*   Updated: 2022/06/30 13:55:48 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	set_map_list(t_info *info, char *line, int *flag)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(line);
	if (is_line_only_space(line) && !(*flag & MAP_EXIST))
		return ;
	while (i < len)
	{
		if (!ft_strchr(" 01NSEW", line[i]))
			print_err(UNEXPECTED_CHAR);
		i++;
	}
	if (!(*flag & MAP_EXIST))
		*flag |= MAP_EXIST;
	plist_add_back(info, line);
}

void	free_parse_list(t_info *info)
{
	t_plist	*cur;
	t_plist	*temp;

	cur = info->head;
	while (cur)
	{
		safety_free((void **)&cur->line);
		temp = cur;
		cur = cur->next;
		safety_free((void **)&temp);
	}
}

int	is_line_only_space(char *line)
{
	if (!line || !*line)
		return (TRUE);
	while (*line)
	{
		if (*line != ' ')
			return (FALSE);
		line++;
	}
	return (TRUE);
}
