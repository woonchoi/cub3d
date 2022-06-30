/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:26:03 by jasong            #+#    #+#             */
/*   Updated: 2022/06/30 14:29:57 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H

# include "cub.h"

/*
** key_event.c
*/
void	init_keys(t_info *info);
int		key_press(int key, t_info *info);
int		key_release(int key, t_info *info);
void	key_update(t_info *info, t_raycast_util *r);

/*
** key_utils.c
*/
void	key_d_press(t_raycast_util *r);
void	key_a_press(t_raycast_util *r);
void	key_w_press(t_info *info, t_raycast_util *r);
void	key_s_press(t_info *info, t_raycast_util *r);

#endif