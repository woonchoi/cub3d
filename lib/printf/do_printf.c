/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 20:36:15 by jasong            #+#    #+#             */
/*   Updated: 2021/09/07 11:02:34 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_format(const char *s, va_list ap, int *count)
{
	if (*s == 'c')
		c_process(ap, count);
	else if (*s == 's')
		s_process(ap, count);
	else if (*s == 'p')
		p_process(ap, count);
	else if (*s == 'd')
		d_process(ap, count);
	else if (*s == 'i')
		i_process(ap, count);
	else if (*s == 'u')
		u_process(ap, count);
	else if (*s == 'x')
		low_hex(ap, count);
	else if (*s == 'X')
		up_hex(ap, count);
	else if (*s == '%')
		print_percent(count);
}

int	do_printf(va_list ap, const char *s)
{
	int		count;

	count = 0;
	if (!s)
		return (count);
	while (*s)
	{
		if (*s == '%')
			check_format(++s, ap, &count);
		else
		{
			ft_putchar_fd(*s, 1);
			count++;
		}
		s++;
	}
	return (count);
}
