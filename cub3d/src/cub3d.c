/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 02:59:27 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/03/23 19:27:17 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_data(void)
{	
	play()->image_address = malloc(sizeof(char *) * 4);
	if (play()->image_address == NULL)
		return (0);
	play()->map_line = NULL;
	play()->player_direc = 'P';
	play()->image_address[0] = NULL;
	play()->image_address[1] = NULL;
	play()->image_address[2] = NULL;
	play()->image_address[3] = NULL;
	play()->ceiling_corol[0] = IS_NOT_RGB;
	play()->floor_corol[0] = IS_NOT_RGB;
	return (1);
}

int	file_extension_check(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (filename[len - 1] != 'b')
		return (0);
	if (filename[len - 2] != 'u')
		return (0);
	if (filename[len - 3] != 'c')
		return (0);
	if (filename[len - 4] != '.')
		return (0);
	return (1);
}

int	is_in_image_or_rgb(void)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (play()->image_address[i] == NULL)
			return (0);
		i++;
	}
	if (play()->ceiling_corol[0] == IS_NOT_RGB)
		return (0);
	if (play()->floor_corol[0] == IS_NOT_RGB)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	char	**map_temp;

	if (argc == 2)
	{
		if (init_data() == 0)
			error_mg("image_address malloc error");
		if (file_extension_check(argv[1]) == 0)
			error_mg("is not .cub file");
		if (read_cub_file(argv[1]))
			error_mg("Wrong Files");
		if (is_in_image_or_rgb() == 0)
			error_mg("is not in image or rgb data");
		map_temp = ft_split(play()->map_line, '\n');
		play()->map = map_temp;
		if (play()->map_line == NULL)
			error_mg("Wrong map Files");
		if (map_error_check())
			error_mg("Invalid map");
		mlx_loop_main();
	}
	else
		error_mg("Invalid input");
}
