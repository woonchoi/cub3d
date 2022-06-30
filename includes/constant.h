/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constant.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <jasong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:29:00 by jasong            #+#    #+#             */
/*   Updated: 2022/06/30 14:30:19 by jasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANT_H
# define CONSTANT_H

# define ARG_ERR "Argument error. (Usage : ./cub3d [*.cub])"
# define NAME_ERR "Not a valid file. (Usage : ./cub3d [*.cub])"
# define MAP_ERR "Wrong mapfile."
# define ELEMENT_ERR "Find wrong element."
# define UNEXPECTED_CHAR "Find unexpected charactor in map."
# define MALLOC_ERR "Unexpected error while malloc."
# define SPLITTED_MAP "Map is split with empty space."
# define WALL_ERR "Map is not covered by wall."
# define DOUBLE_PLAYER "Too many player starting point."
# define NO_PLAYER "Missing player starting point."
# define MLX_ERR "Unexpected error when mlx init."
# define WIN_ERR "Unexpected error when window init."
# define TEXTURE_ERR "Unexpected error when set texture."
# define COLOR_ERR "Wrong color format detected."
# define WALL_IMAGE_WIDTH 51
# define WALL_IMAGE_HEIGHT 51
# define MOVE_SPEED 0.05
# define ROTATE_SPEED 0.05

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1,
}	t_bool;

typedef enum e_validate_bitmask
{
	EMPTY_LINE = 0,
	NO_EXIST = 1,
	SO_EXIST = 2,
	WE_EXIST = 4,
	EA_EXIST = 8,
	F_EXIST = 16,
	C_EXIST = 32,
	NEED_MAP = 63,
	MAP_EXIST = 64,
	ALL_EXIST = 127,
}	t_validate_bitmask;

typedef enum e_key
{
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_W = 13,
	KEY_ESC = 53,
}	t_key;

#endif