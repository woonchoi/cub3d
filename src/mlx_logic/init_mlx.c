/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:52:05 by jasong            #+#    #+#             */
/*   Updated: 2022/06/30 14:09:40 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_logic.h"
#include <stdio.h>

void	init_win(t_info *info)
{
	int	width;
	int	height;

	width = info->screen.width;
	height = info->screen.height;
	info->win_ptr = mlx_new_window(info->mlx_ptr, width, height, "cub3d");
	if (!info->win_ptr)
		print_err(WIN_ERR);
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
