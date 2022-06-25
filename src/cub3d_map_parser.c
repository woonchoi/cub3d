#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <errno.h>
#include "libft.h"
#include "get_next_line.h"

#define ARG_ERR "Too many argument. (Usage : ./cub3d [*.cub])"
#define NAME_ERR "Not a valid file. (Usage : ./cub3d [*.cub])"

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1,
}	t_bool;

// #define TRUE 1
// #define FALSE 0

// typedef enum e_validate_bitmask
// {
// 	EMPTY_LINE = 0,
// 	NO_EXIST = 1,
// 	SO_EXIST = 2,
// 	WE_EXIST = 4,
// 	EA_EXIST = 8,
// 	F_EXIST = 16,
// 	C_EXIST = 32,
// 	MAP_EXIST = 64,
// 	ALL_EXIST = 127,
// }	t_validate_bitmask;

// typedef struct s_texture
// {
// 	char	*north_texture_path;
// 	char	*east_texture_path;
// 	char	*west_texture_path;
// 	char	*south_texture_path;
// }	t_texture;

// typedef struct s_floor_color
// {
// 	int	color_r;
// 	int	color_g;
// 	int	color_b;
// }	t_floor_color;

// typedef struct s_celling_color
// {
// 	int	color_r;
// 	int	color_g;
// 	int	color_b;
// }	t_celling_color;

// typedef struct s_info
// {
// 	char			**map;
// 	int				valid_mask;
// 	t_texture		texture;
// 	t_floor_color	f_color;
// 	t_celling_color	c_color;
// }	t_info;

// int	check_line_empty(char *line)
// {
// 	int	i;

// 	i = 0;
// 	if (line && line[0] == '0')
// 		return (TRUE);
// 	return (FALSE);
// }

// int	set_map_element(t_info *info, char *line, int mask)
// {
// 	if (mask == NO_EXIST)
		
// }

// int	check_valid_line(t_info *info, char *line)
// {
// 	if (check_line_empty(line))
// 		return (EMPTY_LINE);
// 	else if (!strncmp(line, "NO ", 3) && !(info->valid_mask & NO_EXIST))
// 		return (NO_EXIST);
	
// }

// int validate_cubfile(t_info *info, char **map)
// {
// 	int	i;

// 	i = 0;
// 	while (map && map[i])
// 	{
// 		info->valid_mask |= check_valid_line(info, map[i]);
// 		i++;
// 	}
// }

// void    init_info(t_info *info)
// {
// 	info->map = NULL;
// 	info->valid_mask = 0;
// 	info->texture.north_texture_path = NULL;
// 	info->texture.east_texture_path = NULL;
// 	info->texture.west_texture_path = NULL;
// 	info->texture.south_texture_path = NULL;
// 	info->f_color.color_r = 0;
// 	info->f_color.color_g = 0;
// 	info->f_color.color_b = 0;
// 	info->c_color.color_r = 0;
// 	info->c_color.color_g = 0;
// 	info->c_color.color_b = 0;
// }

void	print_err(char *err_string)
{
	ft_putendl_fd(err_string, STDERR_FILENO);
	exit(1);
}

void	terminate_err(char *path)
{
	ft_putstr_fd("cub3d: ", STDERR_FILENO);
	ft_putstr_fd(path, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(strerror(errno), STDERR_FILENO);
	exit(errno);
}

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
		print_err(ARG_ERR)
	
}

int main(int argc, char **argv)
{
	check_valid_arg(argc, argv);
}
