/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:50:38 by jasong            #+#    #+#             */
/*   Updated: 2021/05/13 20:25:09 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*begin;
	char	*end;
	char	*trim;

	if (!set)
		return ((char *)s1);
	if (!s1)
		return (NULL);
	begin = (char *)s1;
	end = (char *)s1 + ft_strlen(s1);
	while (*begin && ft_strchr(set, *begin))
		begin++;
	while (end > begin && ft_strchr(set, *(end - 1)))
		end--;
	trim = (char *)malloc(end - begin + 1);
	if (!trim)
		return (NULL);
	ft_strlcpy(trim, begin, end - begin + 1);
	return (trim);
}
