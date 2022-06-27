#include "cub.h"
#include <stdio.h>

void	fill_img(t_img img, int color, int start, int stop)
{
	int	*bytes;
	int	*end;

	end = (void *)img.data + stop * img.size_l;
	bytes = (int *)((void *)img.data + start * img.size_l);
	while (bytes < end)
		*bytes++ = color;
}

void	draw_floor(t_info *info)
{
	int	horizon;

	horizon = fmax(0, info->screen.height / 2);
	fill_img(info->img, info->f_color, horizon, info->screen.height);
}

void	draw_celling(t_info *info)
{
	int	horizon;

	horizon = fmax(0, info->screen.height / 2);
	fill_img(info->img, info->c_color, 0, horizon);
}

void	init_ray_val(t_info *info, t_raycast *ray_val, int x)
{
	ray_val->camera_x = 2 * x / (double)info->screen.width - 1;
	ray_val->raydir_x = (info->rinfo.dir_x + 
		info->rinfo.plane_x * ray_val->camera_x);
	ray_val->raydir_y = (info->rinfo.dir_y + 
		info->rinfo.plane_y * ray_val->camera_x);
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
		val->perp_wall_dist = (val->map_x - info->rinfo.pos_x +
			(1 - val->step_x) / 2) / val->raydir_x;
	else
		val->perp_wall_dist = (val->map_y - info->rinfo.pos_y +
			(1 - val->step_y) / 2) / val->raydir_y;
}

void	check_draw_startend(t_info *info, t_raycast *val)
{
	val->line_height = (int)(info->screen.height / val->perp_wall_dist);
	val->draw_start =  info->screen.height / 2 - val->line_height / 2;
	if (val->draw_start < 0)
		val->draw_start = 0;
	val->draw_end =  info->screen.height / 2 + val->line_height / 2;
	if (val->draw_end > info->screen.height)
		val->draw_end = info->screen.height - 1;
}

void	find_wall_x(t_info *info, t_raycast *val)
{
	if (val->side == 0)
		val->wall_x = info->rinfo.pos_y +
			(val->perp_wall_dist * val->raydir_y);
	else
		val->wall_x = info->rinfo.pos_x +
			(val->perp_wall_dist * val->raydir_x);
	val->wall_x -= floor(val->wall_x);
}

void	find_texture_x(t_raycast *val)
{
	val->texture_x = (int)(val->wall_x * (double)WALL_IMAGE_WIDTH);
	if (val->side == 0 && val->raydir_x > 0)
		val->texture_x = WALL_IMAGE_WIDTH - val->texture_x - 1.0;
	if (val->side == 1 && val->raydir_y < 0)
		val->texture_x = WALL_IMAGE_WIDTH - val->texture_x - 1.0;
}

void	calculate_texture_pixel_step(t_info *info, t_raycast *val)
{
	val->step = 1.0 * (double)WALL_IMAGE_HEIGHT / (double)val->line_height;
	val->texture_pos = ((double)val->draw_start
		- (double)info->screen.height / 2.0
		+ (double)val->line_height / 2.0) * val->step;
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
	while (y < val->draw_end)
	{
		val->texture_y = (int)val->texture_pos & (WALL_IMAGE_HEIGHT - 1);
		val->texture_pos += val->step;
		color = texture[WALL_IMAGE_HEIGHT * val->texture_y + val->texture_x];
		info->img.data[y * info->img.size_l + x] = color;
		y++;
	}
}

void	raycasting(t_info *info)
{
	int			x;
	t_raycast	ray_val;

	x = 0;
	while (x < info->screen.width * 2)
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
	draw_floor(info);
	draw_celling(info);
	raycasting(info);
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img.img, 0, 0);
	return (0);
}

int main(int argc, char **argv)
{
	t_info	info;

	check_valid_arg(argc, argv);
	init_info(&info, argv[1]);
	mlx_hook(info.win_ptr, 17, 0, &exit_hook, &info);
	mlx_loop_hook(info.mlx_ptr, render_frame, &info);
	mlx_loop(info.mlx_ptr);
	exit(0);
}
