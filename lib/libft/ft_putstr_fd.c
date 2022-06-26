/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 16:17:46 by jasong            #+#    #+#             */
/*   Updated: 2021/05/13 18:20:30 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	unsigned char	c;
	size_t			i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		c = (unsigned char)s[i];
		write(fd, &c, 1);
		i++;
	}
}
