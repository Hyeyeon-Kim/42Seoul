/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:51:03 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/02/15 00:52:00 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	change_pwd(char **env)
{
	char	*newpwd;
	char	*temp;
	int		i;

	newpwd = getcwd(NULL, 1024);
	i = 0;
	while (env[i])
	{
		if (env[i][0] == 'P' && env[i][1] == 'W' && env[i][2] == 'D')
		{
			temp = ft_strjoin("PWD=", newpwd);
			free(newpwd);
			newpwd = temp;
			free(env[i]);
			env[i] = newpwd;
		}
		i++;
	}
}

void	ft_cd(char **cmd)
{
	char	*path;

	path = 0;
	if (cmd[1] != NULL && cmd[1][0] != '~')
	{
		path = cmd[1];
		if (chdir(path) == -1)
			print_errno_message("cd", path, strerror(errno));
		change_pwd(getinstance()->env);
	}
	else if ((cmd[1] == NULL || cmd[1][0] == '~') && cmd[1][1] == 0)
	{
		path = getenv("HOME");
		if (chdir(path) == -1)
			print_err_massage("cd", "HOME not set");
	}
}
