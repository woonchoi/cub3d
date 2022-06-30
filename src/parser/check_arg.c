/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:52:08 by jasong            #+#    #+#             */
/*   Updated: 2022/06/30 13:52:31 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_arg(char *str1, char *str2, char **ret)
{
	if (*str1 && *str2)
	{
		while (*str2 == ' ')
			str2++;
		if (ft_strncmp(str1, str2, ft_strlen(str1)))
			return (FALSE);
	}
	str2 += ft_strlen(str1);
	if (*str2 != ' ')
		return (FALSE);
	if (*str2)
	{
		while (*str2 == ' ')
			str2++;
		if (*str2)
		{
			*ret = str2;
			return (TRUE);
		}
	}
	return (FALSE);
}
