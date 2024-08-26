/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 12:55:21 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2021/08/17 13:57:10 by hyeykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_extension_check(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (filename[len - 1] != 'r')
		return (0);
	if (filename[len - 2] != 'e')
		return (0);
	if (filename[len - 3] != 'b')
		return (0);
	if (filename[len - 4] != '.')
		return (0);
	return (1);
}

void	error_mg(char *error_message)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(error_message, 1);
	write(1, "\n", 1);
	exit(1);
}

char	*file_read_and_insert(char *filename)
{
	int		fd;
	char	*line;
	char	*mapline;

	fd = open(filename, O_RDONLY);
	line = NULL;
	mapline = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		line = ft_strjoin(line, "\n");
		mapline = ft_strjoin(mapline, line);
		free(line);
		line = NULL;
	}
	close(fd);
	return (mapline);
}

void	param_init(t_play *param, char	*mapline)
{
	param->height = 0;
	param->width = 0;
	param->player = 0;
	param->x = 0;
	param->y = 0;
	param->move = 0;
	param->item = 0;
	param->map = ft_split(mapline, '\n');
	free(mapline);
}
