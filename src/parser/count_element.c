#include "parser.h"

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

void	count_wall_floor(char s, int *count)
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
			count_wall_floor(info->map[y][x], &count);
			x++; 
		}
		y++;
	}
	if (check_player == FALSE)
		print_err(NO_PLAYER);
	return (count);
}