/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:53:06 by jasong            #+#    #+#             */
/*   Updated: 2022/06/30 15:58:55 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <stdio.h>

void	check_side(t_info *info, t_raycast *val)
{
	if (!val->side)
		val->perp_wall_dist = (val->map_x - info->rinfo.pos_x
				+ (1 - val->step_x) / 2) / val->raydir_x;
	else
		val->perp_wall_dist = (val->map_y - info->rinfo.pos_y
				+ (1 - val->step_y) / 2) / val->raydir_y;
}

void	check_draw_startend(t_info *info, t_raycast *val)
{
	val->line_height = (int)(info->screen.height / val->perp_wall_dist);
	val->draw_start = info->screen.height / 2 - val->line_height / 2;
	if (val->draw_start < 0)
		val->draw_start = 0;
	val->draw_end = info->screen.height / 2 + val->line_height / 2;
	if (val->draw_end > info->screen.height)
		val->draw_end = info->screen.height - 1;
}

void	raycasting(t_info *info)
{
	int			x;
	t_raycast	ray_val;

	x = 0;
	while (x < info->screen.width)
	{
		init_ray_val(info, &ray_val, x);
		set_ray_val_with_dir(info, &ray_val);
		shoot_ray(info, &ray_val);
		check_side(info, &ray_val);
		check_draw_startend(info, &ray_val);
		find_wall_x(info, &ray_val);
		find_texture_x(&ray_val);
		calculate_texture_pixel_step(info, &ray_val);
		draw_texture_to_image(info, &ray_val, x);
		x++;
	}
}

int	render_frame(t_info *info)
{
	key_update(info, &info->rinfo);
	draw_floor(info);
	draw_ceiling(info);
	raycasting(info);
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	info;

	check_valid_arg(argc, argv);
	init_info(&info, argv[1]);
	mlx_hook(info.win_ptr, 17, 0, &exit_hook, &info);
	mlx_hook(info.win_ptr, 2, 1L << 0, &key_press, &info);
	mlx_hook(info.win_ptr, 3, 1L << 1, &key_release, &info);
	mlx_loop_hook(info.mlx_ptr, &render_frame, &info);
	mlx_loop(info.mlx_ptr);
	exit(0);
}
