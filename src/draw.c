/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:32:42 by jasong            #+#    #+#             */
/*   Updated: 2022/06/30 15:56:29 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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

void	draw_ceiling(t_info *info)
{
	int	horizon;

	horizon = fmax(0, info->screen.height / 2);
	fill_img(info->img, info->c_color, 0, horizon);
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
