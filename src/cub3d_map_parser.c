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

#define ARG_ERR "Argument error. (Usage : ./cub3d [*.cub])"
#define NAME_ERR "Not a valid file. (Usage : ./cub3d [*.cub])"
#define MAP_ERR "Wrong mapfile."
#define ELEMENT_ERR "Find wrong element."
#define UNEXPECTED_CHAR "Find unexpected charactor in map."
#define MALLOC_ERR "Unexpected error while malloc."
#define SPLITTED_MAP "Map is split with empty space."

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

typedef struct s_texture
{
	char	*north_texture_path;
	char	*east_texture_path;
	char	*west_texture_path;
	char	*south_texture_path;
}	t_texture;

typedef struct s_floor_color
{
	int	color_r;
	int	color_g;
	int	color_b;
}	t_floor_color;

typedef struct s_celling_color
{
	int	color_r;
	int	color_g;
	int	color_b;
}	t_celling_color;

typedef struct s_plist
{
	char			*line;
	struct s_plist	*next;
}	t_plist;

typedef struct s_info
{
	char			**map;
	int				m_width;
	int				m_height;
	int				m_width_offset;
	t_plist			*head;
	t_texture		texture;
	t_floor_color	f_color;
	t_celling_color	c_color;
}	t_info;

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

void	safety_free(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = 0;
	}
}

int	check_arg(char *str1, char *str2, char **ret)
{
	if (*str1 && *str2)
	{
		while (*str2 == ' ')
			str2++;
		if (ft_strncmp(str1, str2, ft_strlen(str1)))
			return (FALSE);
	}
	str2 += ft_strlen(str1);
	if (str2)
	{
		while (*str2 == ' ')
			str2++;
		if (*str2)
		{
			*ret = str2;
			return (TRUE);
		}
	}
	return (FALSE);
}

// not complete yet
void	set_texture(int *flag, int now_flag)
{
	if (*flag & now_flag)
		print_err(MAP_ERR);
	*flag |= now_flag;
}

void	set_color(int *flag, int now_flag)
{
	if (*flag & now_flag)
		print_err(MAP_ERR);
	*flag |= now_flag;
}
// not complete yet

int	is_line_only_space(char *line)
{
	if (!line || !*line)
		return (TRUE);
	while (*line)
	{
		if (*line != ' ')
			return (FALSE);
		line++;
	}
	return (TRUE);
}

//WIP
void	set_element(char *line, int *flag)
{
	char	*path;

	path = 0;
	if (is_line_only_space(line))
		return ;
	else if (check_arg("NO", line, &path))
		set_texture(flag, NO_EXIST);
	else if (check_arg("SO", line, &path))
		set_texture(flag, SO_EXIST);
	else if (check_arg("WE", line, &path))
		set_texture(flag, WE_EXIST);
	else if (check_arg("EA", line, &path))
		set_texture(flag, EA_EXIST);
	else if (check_arg("F", line, &path))
		set_color(flag, F_EXIST);
	else if (check_arg("C", line, &path))
		set_color(flag, C_EXIST);
	else
		print_err(ELEMENT_ERR);
}
//WIP

t_plist	*create_plist_node(char *line)
{
	t_plist	*ret;

	ret = (t_plist *)malloc(sizeof(t_plist));
	if (!ret)
		print_err(MALLOC_ERR);
	ret->line = ft_strdup(line);
	ret->next = NULL;
	return (ret);
}

void	plist_add_back(t_info *info, char *line)
{
	t_plist	*cur;

	if (!info->head)
		info->head = create_plist_node(line);
	else
	{
		cur = info->head;
		while (cur->next)
			cur = cur->next;
		cur->next = create_plist_node(line);
	}
}

void	set_map_list(t_info *info, char *line, int *flag)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(line);
	if (is_line_only_space(line) && !(*flag & MAP_EXIST))
		return ;
	while (i < len)
	{
		if (!ft_strchr(" 01NSEW", line[i]))
			print_err(UNEXPECTED_CHAR);
		i++;
	}
	if (!(*flag & MAP_EXIST))
		*flag |= MAP_EXIST;
	plist_add_back(info, line);
}

void	get_valid_line_length(t_info *info, char *line)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	if (!line || !*line)
		return ;
	while (line[i])
	{
		if (line[i] != ' ')
		{
			len = i;
			if (len < info->m_width_offset)
				info->m_width_offset = len;
		}
		i++;
	}
	if (len > info->m_width)
		info->m_width = len;
}

void	malloc_map(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	info->m_width -= (info->m_width_offset - 3);
	info->m_height += 3;
	info->map = (char **)calloc(info->m_height, sizeof(char *));
	if (!info->map)
		print_err(MALLOC_ERR);
	while (i < info->m_height - 1)
	{
		j = 0;
		info->map[i] = (char *)malloc((info->m_width + 1) * sizeof(char));
		if (!info->map[i])
			print_err(MALLOC_ERR);
		while (j < info->m_width)
		{
			info->map[i][j] = ' ';
			j++;
		}
		info->map[i][j] = 0;
		i++;
	}
}

void	malloc_map_with_size(t_info *info)
{
	int		map_end_flag;
	t_plist	*cur;

	info->m_width = 0;
	info->m_height = 0;
	info->m_width_offset = INT_MAX;
	map_end_flag = FALSE;
	cur = info->head;
	while (cur)
	{
		if (is_line_only_space(cur->line))
			map_end_flag = TRUE;
		else if (!is_line_only_space(cur->line) && map_end_flag == TRUE)
			print_err(SPLITTED_MAP);
		else
		{
			info->m_height++;
			get_valid_line_length(info, cur->line);
		}
		cur = cur->next;
	}
	malloc_map(info);
}

void	create_map_with_list(t_info *info)
{
	t_plist	*cur;
	int		i;
	int		j;

	malloc_map_with_size(info);
	cur = info->head;
	i = 1;
	while (cur)
	{
		j = 1;
		while (j < info->m_width && cur->line[j - 1 + info->m_width_offset])
		{
			info->map[i][j] = cur->line[j - 1 + info->m_width_offset];
			j++;
		}
		cur = cur->next;
		i++;
	}
}

void	parse_map(t_info *info, int fd)
{
	char	*line;
	int		flag;

	flag = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (flag < NEED_MAP)
			set_element(line, &flag);
		else
			set_map_list(info, line, &flag);
		safety_free((void **)&line);
	}
	if (line && flag == ALL_EXIST)
	{
		set_map_list(info, line, &flag);
		safety_free((void **)&line);
	}
	if (flag != ALL_EXIST)
		print_err(MAP_ERR);
	create_map_with_list(info);
}

void	free_parse_list(t_info *info)
{
	t_plist	*cur;
	t_plist *temp;

	cur = info->head;
	while (cur)
	{
		safety_free((void **)&cur->line);
		temp = cur;
		cur = cur->next;
		safety_free((void **)&temp);
	}
}

void	init_map(t_info *info, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd <= 0)
		open_err(path);
	parse_map(info, fd);
	free_parse_list(info);
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
		print_err(NAME_ERR);
}

void    init_info(t_info *info, char *path)
{
	info->head = NULL;
	init_map(info, path);
}

void	print_doublearray_map(t_info *info)
{
	int i;

	i = 0;
	while (i < info->m_width + 2)
	{
		printf("-");
		i++;
	}
	printf("\n");
	i = 0;
	while (info->map[i])
	{
		printf("|%s|\n", info->map[i]);
		i++;
	}
	i = 0;
	while (i < info->m_width + 2)
	{
		printf("-");
		i++;
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	t_info	info;

	check_valid_arg(argc, argv);
	init_info(&info, argv[1]);
	print_doublearray_map(&info);
	exit(0);
}
