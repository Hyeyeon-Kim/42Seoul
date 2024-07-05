/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 04:40:57 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/02/12 16:10:43 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	repeat(char	**cmd)
{
	int	i;
	int	ret;

	i = 1;
	while (cmd[i])
	{
		if (ft_strcmp(cmd[0], "export") == 0)
			ret = check_export(cmd[i]);
		else if (ft_strcmp(cmd[0], "unset") == 0)
			ret = unset_env(cmd[i]);
		i++;
	}
	if (ret == -1)
		print_err_massage(cmd[0], "bad assignment");
}

int	is_built_in(char **cmd)
{
	int	true_;

	true_ = 1;
	if (ft_strcmp(cmd[0], "cd") == 0)
		ft_cd(cmd);
	else if (ft_strcmp(cmd[0], "echo") == 0)
		ft_echo(cmd);
	else if (ft_strcmp(cmd[0], "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(cmd[0], "env") == 0)
		ft_env();
	else if (ft_strcmp(cmd[0], "export") == 0)
		repeat(cmd);
	else if (ft_strcmp(cmd[0], "unset") == 0)
		repeat(cmd);
	else if (ft_strcmp(cmd[0], "exit") == 0)
		ft_exit(cmd);
	else
		true_ = 0;
	return (true_);
}
