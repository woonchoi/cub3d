/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:53:01 by jasong            #+#    #+#             */
/*   Updated: 2022/06/30 14:40:33 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "mlx_logic.h"
#include "cub.h"
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

int	*malloc_texture(void)
{
	int	*texture;
	int	texture_size;
	int	i;

	texture_size = WALL_IMAGE_WIDTH * WALL_IMAGE_HEIGHT;
	texture = (int *)malloc(sizeof(int) * texture_size);
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

void	init_info(t_info *info, char *path)
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
