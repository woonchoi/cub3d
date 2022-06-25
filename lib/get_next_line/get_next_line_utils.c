/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 13:01:04 by jasong            #+#    #+#             */
/*   Updated: 2022/02/18 01:06:09 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	empty_backup(char **backup)
{
	if (!backup)
		return ;
	*backup = (char *)malloc(1);
	if (!*backup)
		return ;
	(*backup)[0] = '\0';
}
