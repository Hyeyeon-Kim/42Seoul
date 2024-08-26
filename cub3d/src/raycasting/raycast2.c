/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:55:28 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/03/22 10:57:06 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	dist(t_ray *ray)
{
	if (ray->side == 0)
		ray->perpwalldist = (ray->map_x - play()->x + \
		(1 - ray->step_x) / 2) / ray->raydir_x;
	else
		ray->perpwalldist = (ray->map_y - play()->y + \
		(1 - ray->step_y) / 2) / ray->raydir_y;
	ray->line_height = HEIGHT / ray->perpwalldist;
	if (ray->side == 0)
		ray->hit_point = play()->y + ray->perpwalldist * ray->raydir_y;
	else
		ray->hit_point = play()->x + ray->perpwalldist * ray->raydir_x;
	ray->hit_point -= (int)ray->hit_point;
}

void	dir_camera_set(t_player player, t_ray *ray, int x)
{
	ray->map_x = play()->x;
	ray->map_y = play()->y;
	ray->camera_x = 2 * x / (double)WIDTH - 1;
	ray->raydir_x = player.dir_x + player.plane_x * ray->camera_x;
	ray->raydir_y = player.dir_y + player.plane_y * ray->camera_x;
}
