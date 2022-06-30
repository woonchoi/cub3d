/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:53:34 by jasong            #+#    #+#             */
/*   Updated: 2022/06/30 14:21:24 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/struct.h"

void	print_doublearray_map(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->m_width + 2)
	{
		printf("-");
		i++;
	}
	printf("\n");
	i = 0;
	while (info->map[i])
	{
		printf("|%s|\n", info->map[i]);
		i++;
	}
	i = 0;
	while (i < info->m_width + 2)
	{
		printf("-");
		i++;
	}
	printf("\n");
}
