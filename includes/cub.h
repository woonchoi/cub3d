/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:28:42 by jasong            #+#    #+#             */
/*   Updated: 2022/06/30 14:40:53 by jasong           ###   ########.fr       */
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



#endif