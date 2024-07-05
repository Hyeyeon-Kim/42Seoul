/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utiles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:15:49 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/03/22 23:09:12 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_play	*play(void)
{
	static t_play	data;

	return (&data);
}

void	error_mg(char *error_message)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(error_message, 1);
	write(1, "\n", 1);
	exit(1);
}

void	all_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
