#include "parser.h"
#include "mlx_logic.h"
#include <stdio.h>

void	init_map(t_info *info, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd <= 0)
		open_err(path);
	parse_map(info, fd);
	free_parse_list(info);
	print_doublearray_map(info);
	validate_map(info);
}

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
		set_rinfo_plane(info, 0.0, 0.66);
	}
	else if (info->map[y][x] == 'W')
	{
		set_rinfo_dir(info, 0.0, -1.0);
		set_rinfo_plane(info, 0.0, -0.66);
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
				info->rinfo.pos_x = (double)x;
				info->rinfo.pos_y = (double)y;
				set_player_direc(info, x, y);
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

void    init_info(t_info *info, char *path)
{
	info->head = NULL;
	init_map(info, path);
	info->screen.width = 1600;
	info->screen.height = 900;
	init_raycast_util(info);
	init_mlx(info);
	printf("pos_x: %f pos_y: %f dir_x: %f dir_y: %f plane_x: %f plane_y: %f\n", info->rinfo.pos_x, info->rinfo.pos_y, info->rinfo.dir_x, info->rinfo.dir_y, info->rinfo.plane_x, info->rinfo.plane_y);
}
