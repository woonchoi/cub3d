#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_texture
{
	int	*north;
	int	*east;
	int	*west;
	int	*south;
}	t_texture;

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}	t_img;

typedef struct s_raycast
{
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		texture_x;
	double	step;
	double	texture_pos;
	int		texture_y;
}	t_raycast;

typedef struct s_plist
{
	char			*line;
	struct s_plist	*next;
}	t_plist;

typedef struct s_raycast_util
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rotate_speed;
}	t_raycast_util;

typedef struct s_screen_size
{
	int	width;
	int	height;
}	t_screen_size;

typedef struct s_info
{
	char			**map;
	int				m_width;
	int				m_height;
	int				m_width_offset;
	t_plist			*head;
	t_texture		texture;
	int				f_color;
	int				c_color;
	t_raycast_util	rinfo;
	t_screen_size	screen;
	t_img			img;
	void			*mlx_ptr;
	void			*win_ptr;
}	t_info;

#endif