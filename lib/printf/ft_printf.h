/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:27:14 by jasong            #+#    #+#             */
/*   Updated: 2022/02/22 18:00:24 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

/*
******************************** ft_printf.c ***********************************
*/

int		ft_printf(const char *s, ...);

/*
******************************** do_printf.c ************************************
*/

int		do_printf(va_list ap, const char *s);

/*
******************************* process_one.c **********************************
*/

void	c_process(va_list ap, int *count);
void	s_process(va_list ap, int *count);
void	p_process(va_list ap, int *count);
void	d_process(va_list ap, int *count);
void	i_process(va_list ap, int *count);

/*
******************************* process_two.c **********************************
*/

void	u_process(va_list ap, int *count);
void	low_hex(va_list ap, int *count);
void	up_hex(va_list ap, int *count);
void	print_percent(int *count);

/*
*********************************** utils.c *************************************
*/

int		print_add(unsigned long long add, int reset);
int		count_len(long long num);
int		print_low_hex(unsigned int num, int reset);
int		print_up_hex(unsigned int num, int reset);

#endif
