/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:40:38 by jasong            #+#    #+#             */
/*   Updated: 2022/02/18 01:06:18 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	empty_backup(char **backup)
{
	if (!backup)
		return ;
	*backup = (char *)malloc(1);
	if (!*backup)
		return ;
	(*backup)[0] = '\0';
}
