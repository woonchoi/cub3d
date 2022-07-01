/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:04:12 by jasong            #+#    #+#             */
/*   Updated: 2022/07/01 12:22:09 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	key_press(int key, t_info *info)
{
	if (key == KEY_ESC)
		exit_hook(info);
	if (key == KEY_A)
		info->key.a = 1;
	if (key == KEY_D)
		info->key.d = 1;
	if (key == KEY_W)
		info->key.w = 1;
	if (key == KEY_S)
		info->key.s = 1;
	if (key == KEY_LEFT)
		info->key.left_arrow = 1;
	if (key == KEY_RIGHT)
		info->key.right_arrow = 1;
	return (0);
}

int	key_release(int key, t_info *info)
{
	if (key == KEY_A)
		info->key.a = 0;
	if (key == KEY_D)
		info->key.d = 0;
	if (key == KEY_W)
		info->key.w = 0;
	if (key == KEY_S)
		info->key.s = 0;
	if (key == KEY_LEFT)
		info->key.left_arrow = 0;
	if (key == KEY_RIGHT)
		info->key.right_arrow = 0;
	return (0);
}

void	key_update(t_info *info, t_raycast_util *r)
{
	if (info->key.a)
		key_a_press(info, r);
	if (info->key.s)
		key_s_press(info, r);
	if (info->key.d)
		key_d_press(info, r);
	if (info->key.w)
		key_w_press(info, r);
	if (info->key.left_arrow)
		key_left_press(r);
	if (info->key.right_arrow)
		key_right_press(r);
}
