/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_logic.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:29:31 by jasong            #+#    #+#             */
/*   Updated: 2022/06/30 14:29:31 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_LOGIC_H
# define MLX_LOGIC_H

# include "mlx.h"
# include "constant.h"
# include "struct.h"
# include "cub_util.h"
# include <stdlib.h>

void	init_mlx(t_info *info);
void	init_win(t_info *info);
void	init_screen_img(t_info *info);

#endif