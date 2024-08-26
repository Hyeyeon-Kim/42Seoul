/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:33:55 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/02/14 02:01:09 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_export2(int idx, char *str)
{
	int		i;
	char	**new;

	new = malloc(sizeof(char *) * (idx + 2));
	if (new == NULL)
		return (-1);
	i = -1;
	while (getinstance()->env[++i])
		new[i] = ft_strdup(getinstance()->env[i]);
	add_export(str, new, i);
	remove_envp();
	getinstance()->env = new;
	return (0);
}

int	check_export(char *str)
{
	int		i;

	if (str[0] == '=' || str[0] == '\0' || ft_strlen(str) == 1)
		return (-1);
	i = -1;
	while (getinstance()->env[++i] != NULL)
	{
		if (!ft_strncmp(getinstance()->env[i], str, ft_wordcount(str, '=') + 2))
		{
			free(getinstance()->env[i]);
			getinstance()->env[i] = ft_strdup(str);
			if (getinstance()->env[i] == 0)
				return (-1);
			return (0);
		}
	}
	return (check_export2(i, str));
}
