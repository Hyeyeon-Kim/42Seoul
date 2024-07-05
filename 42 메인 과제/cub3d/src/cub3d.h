/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 20:51:33 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/03/23 22:41:53 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_X_BUTTON 17

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

# define IS_NOT_RGB 300

# define WIDTH 1600
# define HEIGHT 1200

typedef struct s_player
{
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
}					t_player;

typedef struct s_texture
{
	char			*adr;
	void			*img;
	unsigned int	*img_data;
	int				bpp;
	int				size_line;
	int				endian;
	int				width;
	int				height;
}					t_texture;

typedef struct s_ray
{
	double			raydir_x;
	double			raydir_y;
	double			sidedist_x;
	double			sidedist_y;
	double			camera_x;
	double			deltadist_x;
	double			deltadist_y;
	double			perpwalldist;
	double			hit_point;
	int				step_x;
	int				step_y;
	int				side;
	int				tex_x;
	int				line_height;
	int				map_x;
	int				map_y;
	int				nswe;
}					t_ray;

typedef struct s_play
{
	void				*mlx;
	void				*win;
	void				*screen;
	unsigned int		*screen_data;
	int					bpp;
	int					size_line;
	int					endian;
	char				**image_address;
	char				**map;
	char				**map_check;
	int					ceiling_corol[3];
	int					floor_corol[3];
	char				*map_line;
	int					ret;
	int					colum;
	int					max_len;
	struct s_player		player;
	struct s_texture	texture[4];
	char				player_direc;
	double				x;
	double				y;
}t_play;

t_play	*play(void);
void	error_mg(char *error_message);
int		get_init_data(char *line);
int		get_map_data(char **line);
int		map_error_check(void);
int		error_check_map_components(void);
int		read_cub_file(char *file_name);
void	mlx_loop_main(void);
int		key_press(int keycode);
int		raycasting(void);
void	cast(t_ray *ray);
void	sum_ray(t_ray *ray);
void	check_step(t_ray *ray);
void	dist(t_ray *ray);
void	dir_camera_set(t_player player, t_ray *ray, int x);
void	draw(t_texture *texture, t_ray *ray, int x);
void	turn_left(t_player *player);
void	turn_right(t_player *player);
int		key_press(int keycode);
void	move_forward(t_player *player, char **map);
void	move_backward(t_player *player, char **map);
void	move_left(t_player *player, char **map);
void	move_right(t_player *player, char **map);
void	all_free(char **str);
void	dfs(int y, int x, int i);
#endif
