/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 13:00:56 by jasong            #+#    #+#             */
/*   Updated: 2022/06/25 19:58:42 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_newline(char *backup)
{
	int		i;

	if (!backup)
		return (-1);
	i = -1;
	while (backup[++i])
	{
		if (backup[i] == '\n')
			return (i);
	}
	return (-1);
}

static int	split_newline(char **line, char **backup, int loc)
{
	int		i;
	int		len;
	char	*tmp;

	i = -1;
	len = 0;
	*line = (char *)malloc(loc + 1);
	if (!(*line))
		return (-1);
	while (++i < loc)
		(*line)[i] = (*backup)[i];
	(*line)[i] = '\0';
	while ((*backup)[len])
		len++;
	tmp = (char *)malloc(len - loc);
	if (!tmp)
		return (-1);
	while ((*backup)[++i])
		tmp[i - loc - 1] = (*backup)[i];
	tmp[i - loc - 1] = '\0';
	free(*backup);
	*backup = tmp;
	return (1);
}

static int	join_backup(char **backup, char *buf, int size)
{
	int		b_len;
	char	*tmp;
	int		i;

	if (!backup)
		return (-1);
	if (!(*backup))
		empty_backup(backup);
	b_len = ft_strlen(*backup);
	tmp = (char *)malloc(b_len + size + 1);
	if (!tmp)
		return (-1);
	i = -1;
	while ((*backup)[++i])
		tmp[i] = (*backup)[i];
	while (*buf)
		tmp[i++] = *buf++;
	tmp[i] = '\0';
	free(*backup);
	*backup = tmp;
	return (1);
}

static int	eof_read(char **backup, char **line, int size, int i)
{
	int		len;

	if (size < 0)
		return (-1);
	if (!backup)
		return (-1);
	if (!(*backup))
	{
		*line = (char *)malloc(1);
		if (!*line)
			return (-1);
		(*line)[0] = '\0';
		return (0);
	}
	len = ft_strlen(*backup);
	*line = (char *)malloc(len + 1);
	if (!*line)
		return (-1);
	(*line)[len] = '\0';
	while ((*backup)[++i])
		(*line)[i] = (*backup)[i];
	free(*backup);
	*backup = NULL;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*backup[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			size;
	int			loc;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || !line)
		return (-1);
	loc = check_newline(backup[fd]);
	if (loc >= 0)
		return (split_newline(line, &backup[fd], loc));
	while (1)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size <= 0)
			break ;
		buf[size] = '\0';
		if (join_backup(&backup[fd], buf, size) < 0)
			return (-1);
		loc = check_newline(backup[fd]);
		if (loc >= 0)
			return (split_newline(line, &backup[fd], loc));
	}
	return (eof_read(&backup[fd], line, size, -1));
}
