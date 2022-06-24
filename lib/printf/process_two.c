/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:14:47 by jasong            #+#    #+#             */
/*   Updated: 2021/09/12 20:18:04 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	u_process(va_list ap, int *count)
{
	unsigned int	num;

	num = va_arg(ap, unsigned int);
	ft_putnbr_fd(num, 1);
	*count += count_len(num);
}

void	low_hex(va_list ap, int *count)
{
	unsigned int	num;

	num = va_arg(ap, unsigned int);
	*count += print_low_hex(num, 0);
	print_low_hex(0, 1);
}

void	up_hex(va_list ap, int *count)
{
	unsigned int	num;

	num = va_arg(ap, unsigned int);
	*count += print_up_hex(num, 0);
	print_up_hex(0, 1);
}

void	print_percent(int *count)
{
	ft_putchar_fd('%', 1);
	*count += 1;
}
