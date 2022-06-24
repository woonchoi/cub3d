/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 10:53:55 by jasong            #+#    #+#             */
/*   Updated: 2021/05/13 20:20:35 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	len;
	int	flag;
	int	location;

	i = 0;
	flag = 0;
	location = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s[i] == (unsigned char)c)
		{
			flag = 1;
			location = i;
		}
		i++;
	}
	if (flag)
		return ((char *)s + location);
	return (NULL);
}
