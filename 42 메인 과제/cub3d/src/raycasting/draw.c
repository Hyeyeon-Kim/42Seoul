/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:55:20 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/03/22 20:49:44 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	find_which_wall(t_ray *ray)
{
	if (ray->side == 1 && ray->raydir_y < 0)
		ray->nswe = 0;
	if (ray->side == 1 && ray->raydir_y > 0)
		ray->nswe = 1;
	if (ray->side == 0 && ray->raydir_x < 0)
		ray->nswe = 2;
	if (ray->side == 0 && ray->raydir_x > 0)
		ray->nswe = 3;
}

int	itorgb(int r, int g, int b)
{
	int		num;

	num = 0;
	if (256 <= r || 256 <= g || 256 <= b)
		error_mg("rgb out of range char");
	num = num + (r << 16);
	num = num + (g << 8);
	num = num + b;
	return (num);
}

void	draw_fnc(int x, int i)
{
	int	temp;
	int	color1;
	int	color2;
	int	color3;
	int	temp_int;

	while (i < HEIGHT)
	{
		temp = (play()->size_line / 4) * i + x;
		if (i > HEIGHT / 2)
		{
			color1 = play()->floor_corol[0];
			color2 = play()->floor_corol[1];
			color3 = play()->floor_corol[2];
		}
		else
		{
			color1 = play()->ceiling_corol[0];
			color2 = play()->ceiling_corol[1];
			color3 = play()->ceiling_corol[2];
		}
		temp_int = itorgb(color1, color2, color3);
		play()->screen_data[temp] = temp_int;
		i++;
	}
}

void	draw_texture(t_texture *texture,
		t_ray *ray, int *st_end)
{
	double		step;
	double		temp_y;
	int			tex_y;

	temp_y = 0;
	step = 1.0 * texture[ray->nswe].height / ray->line_height;
	while (st_end[0] < st_end[1])
	{
		tex_y = temp_y;
		play()->screen_data[(play()->size_line / 4) * st_end[0] + st_end[2]]
		= texture[ray->nswe].img_data[(texture[ray->nswe].size_line / 4)
		* tex_y + ray->tex_x];
		st_end[0]++;
		temp_y += step;
	}
}

void	draw(t_texture *texture, t_ray *ray, int x)
{
	int		st_end[3];

	st_end[0] = HEIGHT / 2 - ray->line_height / 2;
	st_end[1] = HEIGHT / 2 + ray->line_height / 2;
	st_end[2] = x;
	if (st_end[0] < 0)
		st_end[0] = 0;
	if (st_end[1] > HEIGHT)
		st_end[1] = HEIGHT;
	find_which_wall(ray);
	ray->tex_x = ray->hit_point * texture[ray->nswe].width;
	if (ray->side == 0 && ray->raydir_x > 0)
		ray->tex_x = texture[ray->nswe].width - (ray->tex_x + 1);
	if (ray->side == 1 && ray->raydir_y < 0)
		ray->tex_x = texture[ray->nswe].width - (ray->tex_x + 1);
	draw_fnc(x, 0);
	draw_texture(texture, ray, st_end);
}
