/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:27:19 by jasong            #+#    #+#             */
/*   Updated: 2021/05/10 13:35:51 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char		zero;
	long long	nb;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -(long long)n;
	}
	else
		nb = (long long)n;
	zero = '0';
	if (nb < 10)
	{
		zero += nb;
		ft_putchar_fd(zero, fd);
	}
	else
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
}
