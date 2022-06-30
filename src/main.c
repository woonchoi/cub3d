/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:53:06 by jasong            #+#    #+#             */
/*   Updated: 2022/06/30 14:53:20 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <stdio.h>

void	init_ray_val(t_info *info, t_raycast *ray_val, int x)
{
	ray_val->camera_x = 2 * x / (double)info->screen.width - 1;
	ray_val->raydir_x = (info->rinfo.dir_x + info->rinfo.plane_x
			* ray_val->camera_x);
	ray_val->raydir_y = (info->rinfo.dir_y + info->rinfo.plane_y
			* ray_val->camera_x);
	ray_val->map_x = (int)info->rinfo.pos_x;
	ray_val->map_y = (int)info->rinfo.pos_y;
	ray_val->delta_dist_x = fabs(1 / ray_val->raydir_x);
	ray_val->delta_dist_y = fabs(1 / ray_val->raydir_y);
	ray_val->hit = FALSE;
}

void	set_ray_val_with_dir(t_info *info, t_raycast *val)
{
	if (val->raydir_x < 0)
	{
		val->step_x = -1;
		val->side_dist_x = ((info->rinfo.pos_x - val->map_x)
				* val->delta_dist_x);
	}
	else
	{
		val->step_x = 1;
		val->side_dist_x = ((1.0 + val->map_x - info->rinfo.pos_x)
				* val->delta_dist_x);
	}
	if (val->raydir_y < 0)
	{
		val->step_y = -1;
		val->side_dist_y = ((info->rinfo.pos_y - val->map_y)
				* val->delta_dist_y);
	}
	else
	{
		val->step_y = 1;
		val->side_dist_y = ((1.0 + val->map_y - info->rinfo.pos_y)
				* val->delta_dist_y);
	}
}

void	shoot_ray(t_info *info, t_raycast *val)
{
	while (!val->hit)
	{
		if (val->side_dist_x < val->side_dist_y)
		{
			val->side_dist_x += val->delta_dist_x;
			val->map_x += val->step_x;
			val->side = 0;
		}
		else
		{
			val->side_dist_y += val->delta_dist_y;
			val->map_y += val->step_y;
			val->side = 1;
		}
		if (info->map[val->map_y][val->map_x] != '0')
			val->hit = TRUE;
	}
}

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

void	find_wall_x(t_info *info, t_raycast *val)
{
	if (val->side == 0)
		val->wall_x = info->rinfo.pos_y
			+ (val->perp_wall_dist * val->raydir_y);
	else
		val->wall_x = info->rinfo.pos_x
			+ (val->perp_wall_dist * val->raydir_x);
	val->wall_x -= floor(val->wall_x);
}

void	find_texture_x(t_raycast *val)
{
	val->texture_x = (int)(val->wall_x * (double)WALL_IMAGE_WIDTH);
	if (val->side == 0 && val->raydir_x > 0)
		val->texture_x = WALL_IMAGE_WIDTH - val->texture_x - 1;
	if (val->side == 1 && val->raydir_y < 0)
		val->texture_x = WALL_IMAGE_WIDTH - val->texture_x - 1;
}

void	calculate_texture_pixel_step(t_info *info, t_raycast *val)
{
	val->step = 1.0 * WALL_IMAGE_HEIGHT / val->line_height;
	val->texture_pos = (val->draw_start
			- info->screen.height / 2
			+ val->line_height / 2) * val->step;
}

int	*get_correct_texture(t_info *info, t_raycast *val)
{
	if (val->side == 1 && val->raydir_y < 0)
		return (info->texture.south);
	else if (val->side == 1 && val->raydir_y >= 0)
		return (info->texture.north);
	else if (val->side == 0 && val->raydir_x < 0)
		return (info->texture.west);
	else if (val->side == 0 && val->raydir_x >= 0)
		return (info->texture.east);
	return (NULL);
}

void	draw_texture_to_image(t_info *info, t_raycast *val, int x)
{
	int		y;
	int		color;
	int		*texture;

	y = val->draw_start;
	texture = get_correct_texture(info, val);
	if (texture == NULL)
		print_err(TEXTURE_ERR);
	while (y < val->draw_end)
	{
		val->texture_y = (int)val->texture_pos & 63;
		val->texture_pos += val->step;
		color = texture[WALL_IMAGE_HEIGHT * (val->texture_y + 1)
			- (val->texture_x + 1)];
		info->img.data[y * info->screen.width + x] = color;
		y++;
	}
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
