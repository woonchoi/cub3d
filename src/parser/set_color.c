#include "parser.h"

int	*get_correct_color_pos(t_info *info, int now_flag)
{
	if (now_flag == F_EXIST)
		return (&(info->f_color));
	else if (now_flag == C_EXIST)
		return (&(info->c_color));
	return (NULL);
}

void	trim_line(char **line)
{
	while (**line == ' ')
		(*line)++;
}

int	find_strange_char_remain(char **line)
{
	while (**line)
	{
		if (**line != ' ')
			return (TRUE);
		(*line)++;
	}
	return (FALSE);
}

int	atoi_rgb(char **line, int check_next)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	trim_line(line);
	while (ft_isdigit(**line))
	{
		ret = ret * 10 + (**line - '0');
		(*line)++;
		i++;
	}
	if (i > 3 || i == 0 || ret > 255 || ret < 0)
		return (-1);
	trim_line(line);
	if (check_next && **line == ',')
		(*line)++;
	else if (check_next)
		return (-1);
	if (!check_next && find_strange_char_remain(line))
		return (-1);
	return (ret);
}

void	set_color(t_info *info, char *line, int *flag, int now_flag)
{
	int	r;
	int	g;
	int	b;
	int	*color;

	if (*flag & now_flag)
		print_err(MAP_ERR);
	*flag |= now_flag;
	color = get_correct_color_pos(info, now_flag);
	r = atoi_rgb(&line, TRUE);
	if (r == -1)
		print_err(COLOR_ERR);
	g = atoi_rgb(&line, TRUE);
	if (g == -1)
		print_err(COLOR_ERR);
	b = atoi_rgb(&line, FALSE);
	if (b == -1)
		print_err(COLOR_ERR);
	*color = (r << 16) | (g << 8) | b;
}
