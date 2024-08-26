/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 20:41:20 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/03/23 22:41:30 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	turn_left(t_player *player)
{
	double		temp_x;
	double		temp_y;
	double		temp_px;
	double		temp_py;
	double		seta;

	temp_x = player->dir_x;
	temp_y = player->dir_y;
	temp_px = player->plane_x;
	temp_py = player->plane_y;
	seta = (M_PI / 180) * 10;
	player->dir_x = temp_x * cos(-seta) - temp_y * sin(-seta);
	player->dir_y = temp_x * sin(-seta) + temp_y * cos(-seta);
	player->plane_x = temp_px * cos(-seta) - temp_py * sin(-seta);
	player->plane_y = temp_px * sin(-seta) + temp_py * cos(-seta);
}

void	turn_right(t_player *player)
{
	double		temp_x;
	double		temp_y;
	double		temp_px;
	double		temp_py;
	double		seta;

	temp_x = player->dir_x;
	temp_y = player->dir_y;
	temp_px = player->plane_x;
	temp_py = player->plane_y;
	seta = (M_PI / 180) * 10;
	player->dir_x = temp_x * cos(seta) - temp_y * sin(seta);
	player->dir_y = temp_x * sin(seta) + temp_y * cos(seta);
	player->plane_x = temp_px * cos(seta) - temp_py * sin(seta);
	player->plane_y = temp_px * sin(seta) + temp_py * cos(seta);
}

int	key_press(int keycode)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == 13)
		move_forward(&play()->player, play()->map);
	else if (keycode == 1)
		move_backward(&play()->player, play()->map);
	else if (keycode == 0)
		move_left(&play()->player, play()->map);
	else if (keycode == 2)
		move_right(&play()->player, play()->map);
	else if (keycode == 123)
		turn_left(&play()->player);
	else if (keycode == 124)
		turn_right(&play()->player);
	return (0);
}
