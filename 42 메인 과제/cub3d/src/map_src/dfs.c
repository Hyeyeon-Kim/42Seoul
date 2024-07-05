/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:33:50 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/03/25 21:29:36 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_dfs_data(int x_arr[4], int y_arr[4])
{
	x_arr[0] = -1;
	x_arr[1] = 0;
	x_arr[2] = 1;
	x_arr[3] = 0;
	y_arr[0] = 0;
	y_arr[1] = 1;
	y_arr[2] = 0;
	y_arr[3] = -1;
}

int	dfs_2(int x_, int y_, int len)
{
	if (play()->map[y_][x_] == '\0' || play()->map[y_][x_] == ' ' \
		|| ((x_ == 0 || y_ == 0) && play()->map[y_][x_] == '0') ||
		((x_ == len - 1 || y_ == play()->colum - 1) && \
		play()->map[y_][x_] == '0'))
	{
		play()->ret = 1;
		return (1);
	}
	if (play()->map_check[y_][x_] == '0' \
	&& play()->map[y_][x_] == '0')
		dfs(y_, x_, 0);
	return (0);
}

void	dfs(int y, int x, int i)
{
	int	x_arr[4];
	int	y_arr[4];
	int	x_;
	int	y_;
	int	len;

	init_dfs_data(x_arr, y_arr);
	play()->map_check[y][x] = '1';
	while (i < 4)
	{
		x_ = x_arr[i] + x;
		y_ = y_arr[i] + y;
		len = ft_strlen(play()->map[y]);
		if (x_ >= 0 && y_ >= 0 && x_ < len && y_ < play()->colum)
		{
			if (dfs_2(x_, y_, len))
				return ;
		}
		i++;
	}
}
