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

void	calc(t_info *info)
{
	int			x;
	t_raycast	ray_val;

	x = 0;
	while (x < info->screen.width)
	{
		init_ray_val(info, &ray_val, x);
		set_ray_val_with_dir(info, &ray_val);
	}
}

int	render_frame(t_info *info)
{
	draw_floor(info);
	draw_celling(info);
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
