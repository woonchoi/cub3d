/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 10:45:40 by jasong            #+#    #+#             */
/*   Updated: 2021/05/13 20:20:39 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hs, const char *nd, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	find_len;

	if (!hs && !len)
		return (NULL);
	i = -1;
	find_len = ft_strlen(nd);
	if (find_len == 0)
		return ((char *)hs);
	while (hs[++i] && i < len)
	{
		j = -1;
		if (hs[i] == nd[0])
		{
			while (++j < find_len && i + j < len)
			{
				if (hs[i + j] != nd[j])
					break ;
			}
			if (j == find_len)
				return ((char *)hs + i);
		}
	}
	return (NULL);
}
