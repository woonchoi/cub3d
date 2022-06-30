/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:52:52 by jasong            #+#    #+#             */
/*   Updated: 2022/06/30 13:52:52 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	set_dxdy(int *dx, int *dy)
{
	dx[0] = 0;
	dx[1] = -1;
	dx[2] = 1;
	dx[3] = 0;
	dy[0] = -1;
	dy[1] = 0;
	dy[2] = 0;
	dy[3] = 1;
}

int	check_four_direc_char(t_info *info, char *charset, int x, int y)
{
	int	dx[4];
	int	dy[4];
	int	i;

	set_dxdy(dx, dy);
	i = 0;
	while (i < 4)
	{
		if (ft_strchr(charset, info->map[y + dy[i]][x + dx[i]]))
			return (TRUE);
		i++;
	}
	return (FALSE);
}

void	check_wall(t_info *info)
{
	int	y;
	int	x;

	y = 1;
	while (y < info->m_height - 1)
	{
		x = 1;
		while (x < info->m_width - 1)
		{
			if (ft_strchr("0NSEW", info->map[y][x]))
			{
				if (check_four_direc_char(info, " ", x, y))
					print_err(WALL_ERR);
			}
			x++;
		}
		y++;
	}
}
