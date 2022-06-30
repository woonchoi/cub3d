/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:52:39 by jasong            #+#    #+#             */
/*   Updated: 2022/06/30 13:52:39 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	set_element(t_info *info, char *line, int *flag)
{
	char	*path;

	path = 0;
	if (is_line_only_space(line))
		return ;
	else if (check_arg("NO", line, &path))
		set_texture(info, path, flag, NO_EXIST);
	else if (check_arg("SO", line, &path))
		set_texture(info, path, flag, SO_EXIST);
	else if (check_arg("WE", line, &path))
		set_texture(info, path, flag, WE_EXIST);
	else if (check_arg("EA", line, &path))
		set_texture(info, path, flag, EA_EXIST);
	else if (check_arg("F", line, &path))
		set_color(info, path, flag, F_EXIST);
	else if (check_arg("C", line, &path))
		set_color(info, path, flag, C_EXIST);
	else
		print_err(ELEMENT_ERR);
}
