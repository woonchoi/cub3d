/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 18:21:59 by jasong            #+#    #+#             */
/*   Updated: 2021/07/04 12:48:12 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define OVER 1
#define UNDER 2

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static int	flow(long long num, long long sign)
{
	if (sign > 0)
	{
		if (num * sign < 0)
			return (OVER);
	}
	else
	{
		if (num * sign > 0)
			return (UNDER);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	long long		sign;
	long long		i;
	long long		result;

	result = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i++] - '0';
		if (flow(result, sign) == OVER)
			return (-1);
		if (flow(result, sign) == UNDER)
			return (0);
	}
	return ((int)result * (int)sign);
}
