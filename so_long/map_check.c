/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:00:16 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2021/08/19 12:41:59 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	surrounded_walls(char **map, int width, int height)
{
	if (!one_wall_line_case_2(map, 0, 0, width))
		return (0);
	if (!one_wall_line_case_1(map, 0, 0, height))
		return (0);
	if (!one_wall_line_case_2(map, height - 1, 0, width))
		return (0);
	if (!one_wall_line_case_1(map, 0, width - 1, height))
		return (0);
	return (1);
}

void	required_location(t_play *param, int i, int j)
{
	while (param->map[i])
	{
		j = 0;
		while (param->map[i][j])
		{
			if (param->map[i][j] == 'C')
				param->item++;
			else if (param->map[i][j] == 'E')
				param->exit++;
			else if (param->map[i][j] == 'P')
			{
				param->x = j;
				param->y = i;
				param->player = 1;
			}
			j++;
		}
		i++;
	}
	param->width = j * 80;
	param->height = i * 80;
}

int	map_check(t_play *param)
{
	int	i;
	int	width;

	i = 0;
	width = ft_strlen(param->map[i++]);
	while (param->map[i])
	{
		if (width != (int)ft_strlen(param->map[i]))
			return (0);
		i++;
	}
	if (!surrounded_walls(param->map, width, i))
		return (0);
	required_location(param, 0, 0);
	if (param->item < 1 && param->exit < 1 && param->player != 1)
		return (0);
	return (1);
}
