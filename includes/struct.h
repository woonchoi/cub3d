#ifndef STRUCT_H
# define STRUCT_H

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

#endif