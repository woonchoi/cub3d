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
#include "mlx.h"

#define ARG_ERR "Argument error. (Usage : ./cub3d [*.cub])"
#define NAME_ERR "Not a valid file. (Usage : ./cub3d [*.cub])"
#define MAP_ERR "Wrong mapfile."
#define ELEMENT_ERR "Find wrong element."
#define UNEXPECTED_CHAR "Find unexpected charactor in map."
#define MALLOC_ERR "Unexpected error while malloc."
#define SPLITTED_MAP "Map is split with empty space."
#define WALL_ERR "Map is not covered by wall."
#define DOUBLE_PLAYER "Too many player starting point."
#define NO_PLAYER "Missing player starting point."
#define MLX_ERR "Unexpected error when mlx init."
#define WIN_ERR "Unexpected error when window init."

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
	void	*north_texture;
	void	*east_texture;
	void	*west_texture;
	void	*south_texture;
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
	void			*mlx_ptr;
	void			*win_ptr;
}	t_info;

//util need to delete
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
//util need to delete

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

void	set_dxdy(int *dx, int *dy)
{
	dx[0] = 0;
	dx[1] = -1;
	dx[2] = 1;
	dx[3] = 0;
	dy[0] = -1;
	dy[1] = 0;
	dy[2] = 0;
	dy[3] = 1;
}

int	check_four_direc_char(t_info *info, char *charset, int x, int y)
{
	int	dx[4];
	int	dy[4];
	int	i;

	set_dxdy(dx, dy);
	i = 0;
	while (i < 4)
	{
		if (ft_strchr(charset, info->map[y + dy[i]][x + dx[i]]))
			return (TRUE);
		i++;
	}
	return (FALSE);
}

void	check_wall(t_info *info)
{
	int	y;
	int	x;

	y = 1;
	while (y < info->m_height - 1)
	{
		x = 1;
		while (x < info->m_width - 1)
		{
			if (ft_strchr("0NSEW", info->map[y][x]))
			{
				if (check_four_direc_char(info, " ", x, y))
					print_err(WALL_ERR);
			}
			x++;
		}
		y++;
	}
}

void	count_player(char s, int *check_player, int *count)
{
	if (ft_strchr("NSEW", s) && !*check_player)
	{
		*check_player = TRUE;
		(*count)++;
	}
	else if (ft_strchr("NSEW", s) && *check_player)
		print_err(DOUBLE_PLAYER);
}

void	count_wall(char s, int *count)
{
	if (ft_strchr("01", s))
		(*count)++;
}

int	count_element(t_info *info)
{
	int	y;
	int	x;
	int	check_player;
	int	count;

	check_player = FALSE;
	count = 0;
	y = 1;
	while (y < info->m_height - 1)
	{
		x = 1;
		while (x < info->m_width - 1)
		{
			count_player(info->map[y][x], &check_player, &count);
			count_wall(info->map[y][x], &count);
			x++; 
		}
		y++;
	}
	if (check_player == FALSE)
		print_err(NO_PLAYER);
	return (count);
}

int	**malloc_visited_array(t_info *info)
{
	int	i;
	int	**ret;

	i = 0;
	ret = (int **)calloc(sizeof(int *), info->m_height + 1);
	if (!ret)
		print_err(MALLOC_ERR);
	while (i < info->m_height)
	{
		ret[i] = (int *)calloc(sizeof(int), info->m_width);
		if (!ret[i])
			print_err(MALLOC_ERR);
		i++;
	}
	return (ret);
}

// need refactoring because set_dxdy and using stack with recursive is too heavy
int	recursive_dfs(t_info *info, int ***visited, int x, int y)
{
	int	dx[4];
	int	dy[4];
	int	i;
	int count;

	set_dxdy(dx, dy);
	i = 0;
	count = 0;
	while (i < 4)
	{
		if (!(*visited)[y + dy[i]][x + dx[i]])
		{
			if (ft_strchr("01NSEW", info->map[y + dy[i]][x + dx[i]]))
			{
				(*visited)[y + dy[i]][x + dx[i]] = TRUE;
				count += 1;
				count += recursive_dfs(info, visited, x + dx[i], y + dy[i]);
			}
		}
		i++;
	}
	return (count);
}

int	check_splitted_dfs(t_info *info, int x, int y)
{
	int	**visited;
	int	count;
	int	i;

	visited = malloc_visited_array(info);
	count = recursive_dfs(info, &visited, x, y);
	i = 0;
	while (visited[i])
	{
		safety_free((void **)&(visited[i]));
		i++;
	}
	free(visited);
	return (count);
}

void	check_splitted(t_info *info, int count)
{
	int	x;
	int	y;
	int	check;

	y = 1;
	check = FALSE;
	while (y < info->m_height - 1 && !check)
	{
		x = 1;
		while (x < info->m_width - 1 && !check)
		{
			if (ft_strchr("01NSEW", info->map[y][x]))
				check = check_splitted_dfs(info, x, y);
			x++;
		}
		y++;
	}
	if (check != count)
		print_err(SPLITTED_MAP);
}

void	validate_map(t_info *info)
{
	int	count;

	check_wall(info);
	count = count_element(info);
	check_splitted(info, count);
}

void	init_map(t_info *info, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd <= 0)
		open_err(path);
	parse_map(info, fd);
	free_parse_list(info);
	print_doublearray_map(info);
	validate_map(info);
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

void	init_mlx(t_info *info)
{
	info->mlx_ptr = mlx_init();
	if (!info->mlx_ptr)
		print_err(MLX_ERR);
	info->win_ptr = mlx_new_window(info->mlx_ptr, 1600, 900, "cub3d");
	if (!info->win_ptr)
		print_err(WIN_ERR);
}

void    init_info(t_info *info, char *path)
{
	info->head = NULL;
	init_map(info, path);
	init_mlx(info);
}

int	exit_hook(t_info *info)
{
	mlx_destroy_window(info->mlx_ptr, info->win_ptr);
	exit(0);
}

int main(int argc, char **argv)
{
	t_info	info;

	check_valid_arg(argc, argv);
	init_info(&info, argv[1]);
	mlx_hook(info.win_ptr, 17, 0, &exit_hook, &info);
	mlx_loop(info.mlx_ptr);
	exit(0);
}

