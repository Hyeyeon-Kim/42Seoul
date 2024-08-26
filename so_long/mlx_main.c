/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 12:55:13 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/03/19 14:37:52 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ending(t_play *param)
{
	if (param->item == 0 && param->map[param->y][param->x] == 'E')
	{
		ft_putstr_fd("game clear!!\n", 1);
		return (1);
	}
	return (0);
}

void	init_mlx(t_play *param)
{
	param->mlx = mlx_init();
	param->win = mlx_new_window(param->mlx, param->width, \
	param->height, "so_long");

	printf("%d %d\n" ,param->width, param->height);
	
	param->img_hero = mlx_xpm_file_to_image(param->mlx, \
	"images/hero01.xpm", &param->width, &param->height);
	printf("%d %d\n" ,param->width, param->height);

	param->img_key = mlx_xpm_file_to_image(param->mlx, \
	"images/key01.xpm", &param->width, &param->height);
	printf("%d %d\n" ,param->width, param->height);

	param->img_azazel = mlx_xpm_file_to_image(param->mlx, \
	 "images/azazel01.xpm", &param->width, &param->height);
	printf("%d %d\n" ,param->width, param->height);

	param->img_box = mlx_xpm_file_to_image(param->mlx, \
	 "images/box01.xpm", &param->width, &param->height);
	printf("%d %d\n" ,param->width, param->height);

	param->back = mlx_xpm_file_to_image(param->mlx, \
	 "images/background.xpm", &param->width, &param->height);
	printf("%d %d\n" ,param->width, param->height);
}

void	mlx_loop_main(t_play *param)
{
	init_mlx(param);
	print_back(param);
	mlx_loop_hook(param->mlx, &print_image, param);
	mlx_hook(param->win, X_EVENT_KEY_PRESS, 0, &key_press, param);
	mlx_hook(param->win, X_EVENT_X_BUTTON, 0, &x_press_close, param);
	mlx_loop(param->mlx);
}
