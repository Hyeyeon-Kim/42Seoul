/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_map_components.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 09:15:57 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/03/23 22:45:10 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	vector_init2(char c)
{
	if (c == 'S' || c == 'N')
	{
		if (c == 'S')
		{
			play()->player.dir_x = 0;
			play()->player.dir_y = 1;
			play()->player.plane_x = -0.66;
		}
		if (c == 'N')
		{
			play()->player.dir_x = 0;
			play()->player.dir_y = -1;
			play()->player.plane_x = 0.66;
		}
		play()->player.plane_y = 0;
	}
}

void	vector_init(char c)
{
	if (c == 'E' || c == 'W')
	{
		if (c == 'E')
		{
			play()->player.dir_x = 1;
			play()->player.dir_y = 0;
			play()->player.plane_y = 0.66;
		}
		if (c == 'W')
		{
			play()->player.dir_x = -1;
			play()->player.dir_y = 0;
			play()->player.plane_y = -0.66;
		}
		play()->player.plane_x = 0;
	}
	else
		vector_init2(c);
}

int	check_only_one(int i, int j, int *is_in_player)
{
	if (play()->map[i][j] == 'N' || play()->map[i][j] == 'S' || \
		play()->map[i][j] == 'E' || play()->map[i][j] == 'W')
	{
		if (play()->player_direc != 'P')
			return (0);
		play()->player_direc = play()->map[i][j];
		play()->x = j;
		play()->y = i;
		(*is_in_player)++;
		vector_init(play()->map[i][j]);
	}
	return (1);
}

int	error_check_map_components(void)
{
	int	i;
	int	j;
	int	is_in_player;

	i = 0;
	is_in_player = 0;
	while (play()->map[i])
	{
		j = 0;
		while (play()->map[i][j])
		{
			if (play()->map[i][j] != ' ' && play()->map[i][j] != '0' \
			&& play()->map[i][j] != '1' && play()->map[i][j] != 'N' \
			&& play()->map[i][j] != 'S' && play()->map[i][j] != 'E')
				return (1);
			if (check_only_one(i, j, &is_in_player) == 0)
				return (1);
			j++;
		}
		i++;
	}
	if (is_in_player == 0)
		return (1);
	return (0);
}
