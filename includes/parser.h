#ifndef PARSER_H
# define PARSER_H

# include <stdio.h>

# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"
# include "get_next_line.h"
# include "struct.h"
# include "constant.h"
# include "mlx.h"
# include "cub_util.h"

int		check_arg(char *str1, char *str2, char **ret);

int		**malloc_visited_array(t_info *info);
int		recursive_dfs(t_info *info, int ***visited, int x, int y);
int		check_splitted_dfs(t_info *info, int x, int y);
void	check_splitted(t_info *info, int count);

void	count_player(char s, int *check_player, int *count);
void	count_wall(char s, int *count);
int		count_element(t_info *info);

t_plist	*create_plist_node(char *line);
void	plist_add_back(t_info *info, char *line);

void	set_map_list(t_info *info, char *line, int *flag);
void	free_parse_list(t_info *info);
int		is_line_only_space(char *line);


void	set_color(t_info *info, char *line, int *flag, int now_flag);

void	set_texture(t_info *info, char *path, int *flag, int now_flag);

void	set_element(t_info *info, char *line, int *flag);

int		check_valid_filename(char *path);

void	set_dxdy(int *dx, int *dy);
int		check_four_direc_char(t_info *info, char *charset, int x, int y);
void	check_wall(t_info *info);
void	validate_map(t_info *info);

void	get_valid_line_length(t_info *info, char *line);
void	malloc_map(t_info *info);
void	malloc_map_with_size(t_info *info);
void	create_map_with_list(t_info *info);
void	parse_map(t_info *info, int fd);

#endif