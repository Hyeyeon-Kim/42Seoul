/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:30:21 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/02/12 16:10:47 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	minipipe(void)
{
	pid_t	pid;
	int		pipefd[2];

	getinstance()->dummy_in = dup(STDIN_FILENO);
	getinstance()->yes_insert = 2;
	pipe(pipefd);
	pid = fork();
	if (pid == 0)
	{
		ft_close(pipefd[1]);
		dup2(pipefd[0], STDIN);
		getinstance()->pipin = pipefd[0];
		return (2);
	}
	else
	{
		ft_close(pipefd[0]);
		getinstance()->pipout = pipefd[1];
		return (1);
	}
}
