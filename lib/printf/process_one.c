/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 10:57:37 by jasong            #+#    #+#             */
/*   Updated: 2021/09/09 20:47:48 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	c_process(va_list ap, int *count)
{
	char	c;

	c = va_arg(ap, int);
	ft_putchar_fd(c, 1);
	*count += 1;
}

void	s_process(va_list ap, int *count)
{
	char	*s;

	s = va_arg(ap, char *);
	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1);
		*count += 6;
		return ;
	}
	while (*s)
	{
		ft_putchar_fd(*s, 1);
		*count += 1;
		s++;
	}
}

void	p_process(va_list ap, int *count)
{
	unsigned long long	add;

	add = (unsigned long long)va_arg(ap, void *);
	*count += print_add(add, 0);
	print_add(0, 1);
}

void	d_process(va_list ap, int *count)
{
	int	num;

	num = (int)va_arg(ap, int);
	ft_putnbr_fd(num, 1);
	*count += count_len(num);
}

void	i_process(va_list ap, int *count)
{
	int	num;

	num = (int)va_arg(ap, int);
	ft_putnbr_fd(num, 1);
	*count += count_len(num);
}
