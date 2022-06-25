/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:11:18 by jasong            #+#    #+#             */
/*   Updated: 2021/07/04 12:49:51 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;

	if (dst == 0 && src == 0)
		return (NULL);
	dst_tmp = (unsigned char *)dst;
	src_tmp = (unsigned char *)src;
	if (dst < src)
	{
		while (len--)
			*dst_tmp++ = *src_tmp++;
	}
	else
	{
		while (len--)
			*(dst_tmp + len) = *(src_tmp + len);
	}
	return (dst);
}
