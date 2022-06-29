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

void	init_screen_img(t_info *info)
{
	int	width;
	int	height;

	width = info->screen.width;
	height = info->screen.height;
	info->img.img = mlx_new_image(info->mlx_ptr, width, height);
	info->img.data = (int *)mlx_get_data_addr(info->img.img,
		&info->img.bpp, &info->img.size_l, &info->img.endian);
}

int	*malloc_texture(void)
{
	int	*texture;
	int	texture_size;
	int	i;

	texture_size = WALL_IMAGE_WIDTH * WALL_IMAGE_HEIGHT;
	texture =  (int *)malloc(sizeof(int) * texture_size);
	if (!texture)
		print_err(MALLOC_ERR);
	i = 0;
	while (i < texture_size)
	{
		texture[i] = 0;
		i++;
	}
	return (texture);
}

void	init_dir_texture(t_info *info)
{
	info->texture.north = malloc_texture();
	info->texture.east = malloc_texture();
	info->texture.west = malloc_texture();
	info->texture.south = malloc_texture();
}

void	init_keys(t_info *info)
{
	info->key.a = 0;
	info->key.s = 0;
	info->key.d = 0;
	info->key.w = 0;
}

void    init_info(t_info *info, char *path)
{
	info->head = NULL;
	info->screen.width = 1600;
	info->screen.height = 900;
	info->mlx_ptr = mlx_init();
	if (!info->mlx_ptr)
		print_err(MLX_ERR);
	init_dir_texture(info);
	init_map(info, path);
	init_raycast_util(info);
	init_win(info);
	init_screen_img(info);
	init_keys(info);
}
