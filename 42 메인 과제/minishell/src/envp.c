/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:34:20 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/02/12 17:34:21 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_key_value(char *str, char *envs)
{
	int	i;

	i = 0;
	while (str[i] && envs[i] && (str[i] == envs[i]) && (envs[i] != '='))
		i++;
	if ((str[i] == '\0') && (envs[i] == '='))
		return (i);
	return (0);
}

void	set_envp(char **envps)
{
	int		i;

	i = 0;
	while (envps[++i] != NULL)
		i++;
	getinstance()->env = malloc(sizeof(char *) * (i + 1));
	if (getinstance()->env == NULL)
		return (error_handling(2));
	i = -1;
	while (envps[++i])
		getinstance()->env[i] = ft_strdup(envps[i]);
	getinstance()->env[i] = NULL;
}

int	unset_env(char *str)
{
	int	i;
	int	last;

	last = 0;
	while ((getinstance()->env[last]) != NULL)
		last++;
	if (last < 1)
		return (-1);
	i = -1;
	while (getinstance()->env[++i] != NULL)
	{
		if (check_key_value(str, getinstance()->env[i]))
		{
			free(getinstance()->env[i]);
			getinstance()->env[i] = ft_strdup(getinstance()->env[last - 1]);
			free(getinstance()->env[last - 1]);
			getinstance()->env[last - 1] = NULL;
			return (0);
		}
	}
	return (0);
}

void	remove_envp(void)
{
	int		i;

	i = 0;
	while (getinstance()->env[i])
	{
		free(getinstance()->env[i]);
		i++;
	}
	free(getinstance()->env);
}

void	add_export(char *str, char **new, int i)
{
	new[i] = ft_strdup(str);
	new[i + 1] = NULL;
}
