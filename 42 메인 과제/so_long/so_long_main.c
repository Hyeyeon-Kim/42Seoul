/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:15:14 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/03/10 09:01:56 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_play	param;
	char	*mapline;

	if (argc == 1 || argc > 2 || file_extension_check(argv[1]) == 0)
		error_mg("Invalid input");
	mapline = file_read_and_insert(argv[1]);
	if (mapline == NULL)
		error_mg("Empty Files");
	param_init(&param, mapline);
	if (!map_check(&param))
		error_mg("Invalid map");
	mlx_loop_main(&param);
}