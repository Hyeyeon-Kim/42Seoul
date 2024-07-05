/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_wall_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 14:16:00 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2021/08/19 12:40:39 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	one_wall_line_case_1(char **map, int i, int j, int end)
{
	while (i < end)
	{
		if (map[i][j] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	one_wall_line_case_2(char **map, int i, int j, int end)
{
	while (j < end)
	{
		if (map[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}