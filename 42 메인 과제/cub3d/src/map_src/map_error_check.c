/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 21:07:25 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/04/01 17:31:25 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_map_size(void)
{
	int	k;
	int	max_row;
	int	len;

	k = 0;
	max_row = 0;
	while (play()->map[k])
	{
		len = ft_strlen(play()->map[k]);
		if (max_row < len)
			max_row = len;
		k++;
	}
	play()->max_len = max_row;
	play()->colum = k;
	if (k == 0)
		return (0);
	return (1);
}

int	make_map_check(void)
{
	int	i;

	play()->map_check = (char **)malloc(sizeof(char *) * play()->colum);
	if (play()->map_check == NULL)
		return (0);
	i = 0;
	while (play()->map[i])
	{
		play()->map_check[i] = (char *)malloc(ft_strlen(play()->map[i]));
		if (play()->map_check[i] == NULL)
		{
			all_free(play()->map_check);
			return (0);
		}
		ft_memset(play()->map_check[i], '0', ft_strlen(play()->map[i]));
		i++;
	}
	return (1);
}

int	not_recover_wall(void)
{
	int	i;
	int	j;

	if (get_map_size() == 0)
		return (1);
	play()->ret = 0;
	if (make_map_check() == 0)
		return (1);
	i = 0;
	while (play()->map[i])
	{
		j = 0;
		while (play()->map[i][j])
		{
			if (play()->map[i][j] == '0' && play()->map_check[i][j] == '0')
				dfs(i, j, 0);
			j++;
		}
		i++;
	}
	return (play()->ret);
}

int	map_error_check(void)
{
	if (error_check_map_components())
		return (1);
	if (not_recover_wall())
		return (1);
	return (0);
}
