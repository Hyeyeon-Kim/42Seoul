/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:18:15 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/03/04 13:45:20 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_back(t_play *param)
{
	void	*back;
	int		i;
	int		j;

	init(&i, &j);
	back = mlx_xpm_file_to_image(param->mlx, "images/background.xpm", \
	&param->width, &param->height);
	while (param->map[i])
	{
		j = 0;
		while (param->map[i][j])
		{
			mlx_put_image_to_window(param->mlx, param->win, back, \
			j * 80, i * 80);
			j++;
		}
		i++;
	}
}

void	print_obj(t_play *param, int i, int j)
{
	mlx_put_image_to_window(param->mlx, param->win, \
	param->back, j * 80, i * 80);
	if (param->map[i][j] == '1')
		mlx_put_image_to_window(param->mlx, param->win, \
		param->img_box, j * 80, i * 80);
	else if (param->map[i][j] == 'E')
		mlx_put_image_to_window(param->mlx, param->win, \
		param->img_azazel, j * 80, i * 80);
	else if (param->map[i][j] == 'C')
		mlx_put_image_to_window(param->mlx, param->win, \
		param->img_key, j * 80, i * 80);
}

int	print_image(t_play *param)
{
	int	i;
	int	j;

	init(&i, &j);
	while (param->map[i])
	{
		j = 0;
		while (param->map[i][j])
		{
			print_obj(param, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(param->mlx, param->win, param->img_hero, \
	 param->x * 80, param->y * 80);
	return (0);
}
