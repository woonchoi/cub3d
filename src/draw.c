/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:32:42 by jasong            #+#    #+#             */
/*   Updated: 2022/06/30 14:34:32 by jasong           ###   ########.fr       */
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
