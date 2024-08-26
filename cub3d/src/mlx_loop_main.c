/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 20:45:14 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/04/01 17:30:07 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	texture_init(void)
{
	int				i;
	void			*temp;
	unsigned int	*tmp;

	i = 0;
	while (i < 4)
	{
		temp = mlx_xpm_file_to_image(play()->mlx, play()->image_address[i],
				&play()->texture[i].width, &play()->texture[i].height);
		play()->texture[i].img = temp;
		if (play()->texture[i].width < 1 && play()->texture[i].width < 1)
			error_mg("texture open error");
		tmp = (unsigned int *)mlx_get_data_addr(play()->texture[i].img,
				&play()->texture[i].bpp, &play()->texture[i].size_line, \
				&play()->texture[i].endian);
		play()->texture[i].img_data = tmp;
		i++;
	}
}

int	x_press_close(void *param)
{
	(void)param;
	exit(0);
}

void	mlx_loop_main(void)
{
	void	*temp;

	play()->mlx = mlx_init();
	temp = mlx_new_window(play()->mlx, WIDTH, HEIGHT, "cub3D");
	play()->win = temp;
	texture_init();
	mlx_hook(play()->win, 2, 0, key_press, &play);
	mlx_hook(play()->win, 17, 0, x_press_close, &play);
	mlx_loop_hook(play()->mlx, raycasting, &play);
	mlx_loop(play()->mlx);
}
