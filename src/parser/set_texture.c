#include "parser.h"

void	**get_correct_texture_with_flag(t_info *info, int now_flag)
{
	if (now_flag == NO_EXIST)
		return (&(info->texture.north));
	else if (now_flag == SO_EXIST)
		return (&(info->texture.south));
	else if (now_flag == EA_EXIST)
		return (&(info->texture.east));
	else if (now_flag == WE_EXIST)
		return (&(info->texture.west));
	return (NULL);
}

void	set_texture(t_info *info, char *path, int *flag, int now_flag)
{
	void	**texture;
	int		img_width;
	int		img_height;

	img_width = WALL_IMAGE_WIDTH;
	img_height = WALL_IMAGE_HEIGHT;
	if (*flag & now_flag)
		print_err(MAP_ERR);
	*flag |= now_flag;
	texture = get_correct_texture_with_flag(info, now_flag);
	if (!texture)
		print_err(TEXTURE_ERR);
	*texture = mlx_xpm_file_to_image(info->mlx_ptr, path,
		&img_width, &img_height);
	if (!*texture)
		open_err(path);
}
