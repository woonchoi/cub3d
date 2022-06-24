/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 09:44:05 by jasong            #+#    #+#             */
/*   Updated: 2021/05/13 20:21:16 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	s_len;
	size_t	d_len;
	size_t	i;
	size_t	j;

	s_len = ft_strlen(src);
	d_len = ft_strlen(dst);
	i = 0;
	j = 0;
	if (dstsize < d_len)
		return (s_len + dstsize);
	else
	{
		while (dst[i])
			i++;
		while (src[j] && i + 1 < dstsize)
			dst[i++] = src[j++];
		dst[i] = '\0';
		return (s_len + d_len);
	}
}
