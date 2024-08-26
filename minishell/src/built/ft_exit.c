/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:22:22 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/02/12 16:10:38 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_isdigit_str(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (ft_isdigit(str[idx]) == 0)
			return (0);
		idx++;
	}
	return (1);
}

void	ft_exit(char **cmd)
{
	int	i;
	int	exit_status;

	i = 0;
	while (cmd[i] != NULL)
		i++;
	if (i == 1)
		exit(0);
	else if (i == 2 && ft_isdigit_str(cmd[1]))
		exit_status = ft_atoi(cmd[1]);
	else if (i > 2 && ft_isdigit_str(cmd[1]))
	{
		print_err_massage("exit", "too many arguments");
		return ;
	}
	else
	{
		print_err_massage("exit", "numeric argument required");
		exit(255);
	}
	exit(exit_status);
}
