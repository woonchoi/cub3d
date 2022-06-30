/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rinfo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:56:43 by jasong            #+#    #+#             */
/*   Updated: 2022/06/30 14:42:32 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "libft.h"

void	set_rinfo_dir(t_info *info, double dir_x, double dir_y)
{
	info->rinfo.dir_x = dir_x;
	info->rinfo.dir_y = dir_y;
}

void	set_rinfo_plane(t_info *info, double plane_x, double plane_y)
{
	info->rinfo.plane_x = plane_x;
	info->rinfo.plane_y = plane_y;
}

void	set_player_direc(t_info *info, int x, int y)
{
	if (info->map[y][x] == 'N')
	{
		set_rinfo_dir(info, 0.0, -1.0);
		set_rinfo_plane(info, 0.66, 0.0);
	}
	else if (info->map[y][x] == 'S')
	{
		set_rinfo_dir(info, 0.0, 1.0);
		set_rinfo_plane(info, -0.66, 0.0);
	}
	else if (info->map[y][x] == 'E')
	{
		set_rinfo_dir(info, -1.0, 0.0);
		set_rinfo_plane(info, 0.0, -0.66);
	}
	else if (info->map[y][x] == 'W')
	{
		set_rinfo_dir(info, 1.0, 0.0);
		set_rinfo_plane(info, 0.0, 0.66);
	}
}

void	find_player_position(t_info *info)
{
	int	x;
	int	y;

	y = 1;
	while (y < info->m_height - 1)
	{
		x = 1;
		while (x < info->m_width - 1)
		{
			if (ft_strchr("NSEW", info->map[y][x]))
			{
				info->rinfo.pos_x = (double)x + 0.5;
				info->rinfo.pos_y = (double)y + 0.5;
				set_player_direc(info, x, y);
				info->map[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}

void	init_raycast_util(t_info *info)
{
	find_player_position(info);
	info->rinfo.move_speed = 0.05;
	info->rinfo.rotate_speed = 0.05;
}
