/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:03:54 by jasong            #+#    #+#             */
/*   Updated: 2022/07/01 12:09:39 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_keys(t_info *info)
{
	info->key.a = 0;
	info->key.s = 0;
	info->key.d = 0;
	info->key.w = 0;
}

void	key_d_press(t_info *info, t_raycast_util *r)
{
	int	cal_x_pos;
	int	cal_y_pos;

	cal_x_pos = (int)(r->pos_x - r->dir_y * (MOVE_SPEED + 0.3));
	cal_y_pos = (int)(r->pos_y + r->dir_x * (MOVE_SPEED + 0.3));
	if (info->map[(int)r->pos_y][cal_x_pos] != '1')
		r->pos_x += -r->dir_y * MOVE_SPEED;
	if (info->map[cal_y_pos][(int)r->pos_x] != '1')
		r->pos_y += r->dir_x * MOVE_SPEED;
}

void	key_a_press(t_info *info, t_raycast_util *r)
{
	int	cal_x_pos;
	int	cal_y_pos;

	cal_x_pos = (int)(r->pos_x + r->dir_y * (MOVE_SPEED + 0.3));
	cal_y_pos = (int)(r->pos_y - r->dir_x * (MOVE_SPEED + 0.3));
	if (info->map[(int)r->pos_y][cal_x_pos] != '1')
		r->pos_x += r->dir_y * MOVE_SPEED;
	if (info->map[cal_y_pos][(int)r->pos_x] != '1')
		r->pos_y += -r->dir_x * MOVE_SPEED;
}

void	key_w_press(t_info *info, t_raycast_util *r)
{
	int	cal_x_pos;
	int	cal_y_pos;

	cal_x_pos = (int)(r->pos_x + r->dir_x * (MOVE_SPEED + 0.3));
	cal_y_pos = (int)(r->pos_y + r->dir_y * (MOVE_SPEED + 0.3));
	if (info->map[(int)r->pos_y][cal_x_pos] != '1')
		r->pos_x += r->dir_x * MOVE_SPEED;
	if (info->map[cal_y_pos][(int)r->pos_x] != '1')
		r->pos_y += r->dir_y * MOVE_SPEED;
}

void	key_s_press(t_info *info, t_raycast_util *r)
{
	int	cal_x_pos;
	int	cal_y_pos;

	cal_x_pos = (int)(r->pos_x - r->dir_x * (MOVE_SPEED + 0.3));
	cal_y_pos = (int)(r->pos_y - r->dir_y * (MOVE_SPEED + 0.3));
	if (info->map[(int)r->pos_y][cal_x_pos] != '1')
		r->pos_x -= r->dir_x * MOVE_SPEED;
	if (info->map[cal_y_pos][(int)r->pos_x] != '1')
		r->pos_y -= r->dir_y * MOVE_SPEED;
}
