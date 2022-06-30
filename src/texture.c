/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:59:22 by jasong            #+#    #+#             */
/*   Updated: 2022/06/30 15:59:29 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
