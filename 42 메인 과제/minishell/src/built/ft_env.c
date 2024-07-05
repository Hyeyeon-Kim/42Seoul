/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:32:58 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/02/12 16:10:37 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_env(void)
{
	int		i;
	char	**env;

	env = getinstance()->env;
	i = 0;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
}
