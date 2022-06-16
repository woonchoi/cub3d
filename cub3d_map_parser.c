/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 03:37:38 by woonchoi          #+#    #+#             */
/*   Updated: 2022/06/17 04:01:37 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef enum e_validate_bitmask
{
	NO_EXIST = 1,
	SO_EXIST = 2,
	WE_EXIST = 4,
	EA_EXIST = 8,
	F_EXIST = 16,
	C_EXIST = 32,
	MAP_EXIST = 64,
	ALL_EXIST = 127,
}	t_validate_bitmask;

typedef struct s_texture
{
	char	*north_texture_path;
	char	*east_texture_path;
	char	*west_texture_path;
	char	*south_texture_path;
}	t_texture;

typedef struct s_floor_color
{
	int	color_r;
	int	color_g;
	int	color_b;
}	t_floor_color;

typedef struct s_celling_color
{
	int	color_r;
	int	color_g;
	int	color_b;
}	t_celling_color;

typedef struct s_info
{
	char			**map;
	int				valid_mask;
	t_texture		texture;
	t_floor_color	f_color;
	t_celling_color	c_color;
}	t_info;



int validate_cubfile(t_info *info, char **map)
{
}

void    init_info(t_info *info)
{
	info->map = NULL;
	info->valid_mask = 0;
	info->texture.north_texture_path = NULL;
	info->texture.east_texture_path = NULL;
	info->texture.west_texture_path = NULL;
	info->texture.south_texture_path = NULL;
	info->f_color.color_r = 0;
	info->f_color.color_g = 0;
	info->f_color.color_b = 0;
	info->c_color.color_r = 0;
	info->c_color.color_g = 0;
	info->c_color.color_b = 0;
}

int main(int argc, char **argv)
{
	t_info  info;

	if (argc != 2)
		return ;
}
