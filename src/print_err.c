/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:53:10 by jasong            #+#    #+#             */
/*   Updated: 2022/06/30 13:53:10 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void	print_err(char *err_string)
{
	ft_putendl_fd(err_string, STDERR_FILENO);
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(1);
}

void	open_err(char *path)
{
	ft_putstr_fd("cub3d: ", STDERR_FILENO);
	ft_putstr_fd(path, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(strerror(errno), STDERR_FILENO);
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(errno);
}
