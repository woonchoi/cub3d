/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:52:49 by jasong            #+#    #+#             */
/*   Updated: 2022/06/30 13:52:50 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_valid_filename(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 5)
		return (TRUE);
	if (ft_strncmp((path + len - 4), ".cub", 4))
		return (TRUE);
	return (FALSE);
}

void	check_valid_arg(int argc, char **argv)
{
	if (argc != 2)
		print_err(ARG_ERR);
	if (check_valid_filename(argv[1]))
		print_err(NAME_ERR);
}
