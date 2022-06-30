/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:28:48 by jasong            #+#    #+#             */
/*   Updated: 2022/06/30 14:28:56 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_UTIL_H
# define CUB_UTIL_H

# include "struct.h"

void	print_err(char *err_string);
void	open_err(char *path);
void	safety_free(void **ptr);
void	print_doublearray_map(t_info *info);

#endif