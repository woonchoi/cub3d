/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:46:09 by jasong            #+#    #+#             */
/*   Updated: 2022/07/01 11:59:41 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	key_left_press(t_raycast_util *r)
{
	double	cur_dir_x;
	double	cur_plane_x;

	cur_dir_x = r->dir_x;
	r->dir_x = r->dir_x * cos(-ROTATE_SPEED)
		- r->dir_y * sin(-ROTATE_SPEED);
	r->dir_y = cur_dir_x * sin(-ROTATE_SPEED)
		+ r->dir_y * cos(-ROTATE_SPEED);
	cur_plane_x = r->plane_x;
	r->plane_x = r->plane_x * cos(-ROTATE_SPEED)
		- r->plane_y * sin(-ROTATE_SPEED);
	r->plane_y = cur_plane_x * sin(-ROTATE_SPEED)
		+ r->plane_y * cos(-ROTATE_SPEED);
}

void	key_right_press(t_raycast_util *r)
{
	double	cur_dir_x;
	double	cur_plane_x;

	cur_dir_x = r->dir_x;
	r->dir_x = r->dir_x * cos(ROTATE_SPEED)
		- r->dir_y * sin(ROTATE_SPEED);
	r->dir_y = cur_dir_x * sin(ROTATE_SPEED)
		+ r->dir_y * cos(ROTATE_SPEED);
	cur_plane_x = r->plane_x;
	r->plane_x = r->plane_x * cos(ROTATE_SPEED)
		- r->plane_y * sin(ROTATE_SPEED);
	r->plane_y = cur_plane_x * sin(ROTATE_SPEED)
		+ r->plane_y * cos(ROTATE_SPEED);
}
