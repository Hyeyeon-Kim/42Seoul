/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:15:57 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/03/11 14:10:54 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_move(char *move)
{
	ft_putstr_fd(move, 1);
	write(1, "\n", 1);
}

void	move_check(int keycode, t_play *param)
{
	if (keycode == KEY_S && param->map[param->y + 1][param->x] != '1')
	{
		param->y++;
		param->move++;
		print_move(ft_itoa(param->move));
	}
	else if (keycode == KEY_A && param->map[param->y][param->x - 1] != '1')
	{
		param->x--;
		param->move++;
		print_move(ft_itoa(param->move));
	}
	else if (keycode == KEY_D && param->map[param->y][param->x + 1] != '1')
	{
		param->x++;
		param->move++;
		print_move(ft_itoa(param->move));
	}
	else if (keycode == KEY_W && param->map[param->y - 1][param->x] != '1')
	{
		param->y--;
		param->move++;
		print_move(ft_itoa(param->move));
	}
}

int	key_press(int keycode, t_play *param)
{
	if (keycode == KEY_ESC)
		exit(0);
	else
	{
		move_check(keycode, param);
		if (param->map[param->y][param->x] == 'C')
		{
			param->map[param->y][param->x] = '0';
			param->item--;
		}
		if (check_ending(param))
			exit(0);
	}
	return (0);
}

int	x_press_close(void *param)
{
	(void)param;
	exit(0);
}
