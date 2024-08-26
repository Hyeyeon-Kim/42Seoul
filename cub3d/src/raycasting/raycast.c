/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:55:22 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/03/23 22:45:18 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_step(t_ray *ray)
{
	ray->deltadist_x = fabs(1 / ray->raydir_x);
	ray->deltadist_y = fabs(1 / ray->raydir_y);
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (play()->x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - play()->x) * ray->deltadist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (play()->y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - play()->y) * ray->deltadist_y;
	}
}

void	sum_ray(t_ray *ray)
{
	if (ray->sidedist_x < ray->sidedist_y)
	{
		ray->sidedist_x += ray->deltadist_x;
		ray->map_x += ray->step_x;
		ray->side = 0;
	}
	else
	{
		ray->sidedist_y += ray->deltadist_y;
		ray->map_y += ray->step_y;
		ray->side = 1;
	}
}

void	cast(t_ray *ray)
{
	int			x;
	int			hit;

	x = 0;
	while (x <= WIDTH)
	{
		hit = 1;
		dir_camera_set(play()->player, ray, x);
		check_step(ray);
		while (hit)
		{
			sum_ray(ray);
			if (play()->map[ray->map_y][ray->map_x] == '1')
				hit = 0;
		}
		dist(ray);
		draw(play()->texture, ray, x);
		x++;
	}
}

int	raycasting(void)
{
	t_ray			ray;
	void			*temp;
	unsigned int	*temp1;

	temp = mlx_new_image(play()->mlx, WIDTH, HEIGHT);
	play()->screen = temp;
	temp1 = (unsigned int *)mlx_get_data_addr(play()->screen, \
	&play()->bpp, &play()->size_line, &play()->endian);
	play()->screen_data = temp1;
	cast(&ray);
	mlx_clear_window(play()->mlx, play()->win);
	mlx_put_image_to_window(play()->mlx, play()->win, play()->screen, 0, 0);
	mlx_destroy_image(play()->mlx, play()->screen);
	return (0);
}
