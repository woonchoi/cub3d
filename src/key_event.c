#include "cub.h"
#include <stdio.h>

void	key_a_press(t_raycast_util *r)
{
	double	cur_dir_x;
	double	cur_plane_x;

	cur_dir_x = r->dir_x;
	r->dir_x = r->dir_x * cos(ROTATE_SPEED) - r->dir_y * sin(ROTATE_SPEED);
	r->dir_y = cur_dir_x * sin(ROTATE_SPEED) + r->dir_x * cos(ROTATE_SPEED);
	cur_plane_x = r->plane_x;
	r->plane_x = r->plane_x * cos(ROTATE_SPEED) - r->plane_y * sin(ROTATE_SPEED);
	r->plane_y = cur_plane_x * sin(ROTATE_SPEED) + r->plane_y * cos(ROTATE_SPEED);
}

void	key_d_press(t_raycast_util *r)
{
	double	cur_dir_x;
	double	cur_plane_x;

	cur_dir_x = r->dir_x;
	r->dir_x = r->dir_x * cos(-ROTATE_SPEED) - r->dir_y * sin(-ROTATE_SPEED);
	r->dir_y = cur_dir_x * sin(-ROTATE_SPEED) + r->dir_x * cos(-ROTATE_SPEED);
	cur_plane_x = r->plane_x;
	r->plane_x = r->plane_x * cos(-ROTATE_SPEED) - r->plane_y * sin(-ROTATE_SPEED);
	r->plane_y = cur_plane_x * sin(-ROTATE_SPEED) + r->plane_y * cos(-ROTATE_SPEED);
}

void	key_w_press(t_info *info, t_raycast_util *r)
{
	if (!info->map[(int)r->pos_y][(int)(r->pos_x + r->dir_x * MOVE_SPEED)])
		r->pos_x += r->dir_x * MOVE_SPEED;
	if (!info->map[(int)(r->pos_y + r->dir_y * MOVE_SPEED)][(int)r->pos_x])
		r->pos_y += r->dir_y * MOVE_SPEED;
}

void	key_s_press(t_info *info, t_raycast_util *r)
{
	if (!info->map[(int)r->pos_y][(int)(r->pos_x - r->dir_x * MOVE_SPEED)])
		r->pos_x -= r->dir_x * MOVE_SPEED;
	if (!info->map[(int)(r->pos_y - r->dir_y * MOVE_SPEED)][(int)r->pos_x])
		r->pos_y -= r->dir_y * MOVE_SPEED;
}

int	key_press(int key, t_info *info)
{
	if (key == KEY_ESC)
		exit_hook(info);
	if (key == KEY_A)
		info->key.a = 1;
	if (key == KEY_D)
		info->key.s = 1;
	if (key == KEY_W)
		info->key.w = 1;
	if (key == KEY_S)
		info->key.s = 1;
	return (0);
}

int	key_release(int key, t_info *info)
{
	if (key == KEY_A)
		info->key.a = 0;
	if (key == KEY_D)
		info->key.s = 0;
	if (key == KEY_W)
		info->key.w = 0;
	if (key == KEY_S)
		info->key.s = 0;
	return (0);
}

void	key_update(t_info *info, t_raycast_util *r)
{
	if (info->key.a)
		key_a_press(r);
	if (info->key.s)
		key_s_press(info, r);
	if (info->key.d)
		key_d_press(r);
	if (info->key.w)
		key_w_press(info, r);
}