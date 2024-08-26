/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:44:48 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/02/12 16:10:36 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_echo(char **cmd)
{
	int	i;
	int	option;

	i = 1;
	option = 0;
	if (strcmp(cmd[1], "-n") == 0)
	{
		option = 1;
		i++;
	}
	while (cmd[i])
	{
		ft_putstr_fd(cmd[i], STDOUT);
		if (cmd[i + 1] != NULL)
			ft_putchar_fd(' ', STDOUT);
		i++;
	}
	if (!option)
		ft_putchar_fd('\n', STDOUT);
}
