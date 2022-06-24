/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 21:10:22 by jasong            #+#    #+#             */
/*   Updated: 2021/05/13 18:18:26 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;
	size_t			i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = -1;
	dst_tmp = (unsigned char *)dst;
	src_tmp = (unsigned char *)src;
	while (++i < n)
		*(dst_tmp + i) = *(src_tmp + i);
	return (dst);
}
