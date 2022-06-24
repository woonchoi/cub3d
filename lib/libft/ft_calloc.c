/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 14:34:33 by jasong            #+#    #+#             */
/*   Updated: 2021/05/16 16:57:30 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	size_t			len;

	if (size && count)
	{
		len = count * size;
		if ((len / count != size) || (len % size != 0))
			return (NULL);
		tmp = (unsigned char *)malloc(len);
		if (tmp == NULL)
			return (NULL);
		ft_bzero(tmp, size * count);
		return ((void *)tmp);
	}
	else
	{
		tmp = (unsigned char *)malloc(1);
		if (!tmp)
			return (NULL);
		ft_bzero(tmp, 1);
		return (tmp);
	}
}
