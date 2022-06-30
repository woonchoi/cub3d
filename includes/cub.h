/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:28:42 by jasong            #+#    #+#             */
/*   Updated: 2022/06/30 16:03:09 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "mlx.h"
# include "struct.h"
# include "constant.h"
# include "cub_util.h"
# include "key.h"
# include <math.h>
# include <stdlib.h> 

void	check_valid_arg(int argc, char **argv);
void	init_info(t_info *info, char *path);
int		exit_hook(t_info *info);

/*
**	set_rinfo.c
*/

void	init_raycast_util(t_info *info);

/*
** draw.c
*/
void	fill_img(t_img img, int color, int start, int stop);
void	draw_floor(t_info *info);
void	draw_ceiling(t_info *info);
void	draw_texture_to_image(t_info *info, t_raycast *val, int x);

/*
** ray.c
*/
void	init_ray_val(t_info *info, t_raycast *ray_val, int x);
void	set_ray_val_with_dir(t_info *info, t_raycast *val);
void	shoot_ray(t_info *info, t_raycast *val);

/*
** texture.c
*/

void	find_wall_x(t_info *info, t_raycast *val);
void	find_texture_x(t_raycast *val);
void	calculate_texture_pixel_step(t_info *info, t_raycast *val);
int		*get_correct_texture(t_info *info, t_raycast *val);

#endif