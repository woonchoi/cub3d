/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:03:11 by jasong            #+#    #+#             */
/*   Updated: 2021/09/12 20:18:33 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_add(unsigned long long add, int reset)
{
	static int	len;

	if (reset)
	{
		len = 0;
		return (0);
	}
	if (add > 15)
	{
		print_add(add / 16, 0);
		print_add(add % 16, 0);
	}
	else if (add >= 0)
	{
		if (len == 0)
		{
			ft_putstr_fd("0x", 1);
			len = 2;
		}
		ft_putchar_fd("0123456789abcdef"[add], 1);
		len++;
	}
	return (len);
}

int	count_len(long long num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		count++;
	while (num)
	{
		count++;
		num /= 10;
	}
	return (count);
}

int	print_low_hex(unsigned int num, int reset)
{
	static int	count;

	if (reset)
	{
		count = 0;
		return (0);
	}
	if (num > 15)
	{
		print_low_hex(num / 16, 0);
		print_low_hex(num % 16, 0);
	}
	else if (num >= 0)
	{
		ft_putchar_fd("0123456789abcdef"[num], 1);
		count++;
	}
	return (count);
}

int	print_up_hex(unsigned int num, int reset)
{
	static int	count;

	if (reset)
	{
		count = 0;
		return (0);
	}
	if (num > 15)
	{
		print_up_hex(num / 16, 0);
		print_up_hex(num % 16, 0);
	}
	else if (num >= 0)
	{
		ft_putchar_fd("0123456789ABCDEF"[num], 1);
		count++;
	}
	return (count);
}
