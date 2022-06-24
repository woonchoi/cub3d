/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 21:59:09 by jasong            #+#    #+#             */
/*   Updated: 2021/07/04 12:50:12 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_word(char *str, unsigned char c)
{
	int		w_flag;
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	w_flag = 1;
	while (str[i])
	{
		if (str[i] == c)
			w_flag = 1;
		else
		{
			if (w_flag)
				count++;
			w_flag = 0;
		}
		i++;
	}
	return (count);
}

static void	*protect_free(char **arr, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static char	*find_end(char const *s, char c, char **begin)
{
	while (*s && *s == c)
	{
		s++;
		(*begin)++;
	}
	while (*s && *s != c)
		s++;
	return ((char *)s);
}

static size_t	split_process(const char *s, char **ret, char c, size_t cnt)
{
	size_t	i;
	char	*begin;

	i = 0;
	begin = (char *)s;
	while (i < cnt)
	{
		s = find_end(begin, c, &begin);
		ret[i] = (char *)malloc(s - begin + 1);
		if (!ret[i])
			return (++i);
		ft_strlcpy(ret[i++], begin, s - begin + 1);
		begin = (char *)s;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	cnt;
	size_t	i;

	if (!s)
		return (NULL);
	cnt = count_word((char *)s, c);
	ret = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!ret)
		return (NULL);
	ret[cnt] = NULL;
	i = split_process(s, ret, c, cnt);
	if (i)
		return (protect_free(ret, i - 1));
	return (ret);
}
