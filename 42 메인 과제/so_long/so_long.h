/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 14:18:08 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/02/15 02:35:30 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_X_BUTTON 17

# define KEY_W 13      
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

typedef struct s_play
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		x;
	int		y;
	char	**map;
	int		item;
	void	*img_hero;
	void	*img_key;
	void	*img_box;
	void	*img_azazel;
	void	*back;
	int		move;
	int		exit;
	int		player;
}t_play;

int		map_check(t_play *pos);
void	mlx_loop_main(t_play *param);
int		key_press(int keycode, t_play *param);
int		x_press_close(void *param);
int		print_image(t_play *param);
int		one_wall_line_case_1(char **map, int i, int j, int end);
int		one_wall_line_case_2(char **map, int i, int j, int end);
void	print_back(t_play *param);
int		file_extension_check(char *filename);
void	error_mg(char *error_message);
char	*file_read_and_insert(char *filename);
void	param_init(t_play *param, char	*mapline);
int		check_ending(t_play *param);
#endif
