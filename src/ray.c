/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:30:47 by jasong            #+#    #+#             */
/*   Updated: 2022/06/30 15:30:58 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
