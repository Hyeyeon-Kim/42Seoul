/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_directions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 20:44:08 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/03/23 22:44:54 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_player *player, char **map)
{
	int	check_x;
	int	check_y;

	check_x = (int)((play()->x + player->dir_x * 1.2));
	check_y = (int)((play()->y + player->dir_y * 1.2));
	if (map[check_y][check_x] == '1')
		return ;
	play()->x += player->dir_x * 0.2;
	play()->y += player->dir_y * 0.2;
}

void	move_backward(t_player *player, char **map)
{
	int	check_x;
	int	check_y;

	check_x = (int)((play()->x - player->dir_x * 1.2));
	check_y = (int)((play()->y - player->dir_y * 1.2));
	if (map[check_y][check_x] == '1')
		return ;
	play()->x -= player->dir_x * 0.2;
	play()->y -= player->dir_y * 0.2;
}

void	move_left(t_player *player, char **map)
{
	int		check_x;
	int		check_y;
	double	seta;

	seta = (M_PI / 180) * 90;
	check_x = (int)((play()->x + (player->dir_x * cos(-seta)
					- player->dir_y * sin(-seta)) * 1.2));
	check_y = (int)((play()->y + (player->dir_x * sin(-seta)
					+ player->dir_y * cos(-seta)) * 1.2));
	if (map[check_y][check_x] == '1' || map[check_y][check_x] == 'W')
		return ;
	play()->x += (player->dir_x * cos(-seta)
		- player->dir_y * sin(-seta)) * 0.2;
	play()->y += (player->dir_x * sin(-seta)
		+ player->dir_y * cos(-seta)) * 0.2;
}

void	move_right(t_player *player, char **map)
{
	int		check_x;
	int		check_y;
	double	seta;

	seta = (M_PI / 180) * 90;
	check_x = (int)((play()->x + (player->dir_x * cos(seta)
					- player->dir_y * sin(seta)) * 1.2));
	check_y = (int)((play()->y + (player->dir_x * sin(seta)
					+ player->dir_y * cos(seta)) * 1.2));
	if (map[check_y][check_x] == '1')
		return ;
	play()->x += (player->dir_x * cos(seta)
		- player->dir_y * sin(seta)) * 0.2;
	play()->y += (player->dir_x * sin(seta)
		+ player->dir_y * cos(seta)) * 0.2;
}
