#include "parser.h"

void	load_image(t_info *info, int **tex, char *path, t_img *img)
{
	int	x;
	int	y;

	img->img = mlx_xpm_file_to_image(info->mlx_ptr, path,
		&img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp,
		&img->size_l, &img->endian);
	y = 0;
	while (y < img->img_height)
	{
		x = 0;
		while (x < img->img_width)
		{
			(*tex)[img->img_width * y + x] = img->data[img->img_width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(info->mlx_ptr, img->img);
}

int	**get_correct_texture_with_flag(t_info *info, int now_flag)
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
	int		**texture;
	t_img	img;

	if (*flag & now_flag)
		print_err(MAP_ERR);
	*flag |= now_flag;
	texture = get_correct_texture_with_flag(info, now_flag);
	if (!texture)
		print_err(TEXTURE_ERR);
	load_image(info, texture, path, &img);
	if (!*texture)
		open_err(path);
}
