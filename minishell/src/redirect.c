/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:01:35 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/02/15 22:00:06 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ridir_file_open(t_node *token, int flag)
{
	int	fd;

	getinstance()->yes_insert = 0;
	ft_close(getinstance()->fdout);
	fd = open(token->str, flag, 0744);
	getinstance()->fdout = fd;
	if (getinstance()->fdout == -1)
	{
		print_err_massage(token->str, "Invalid file");
		getinstance()->ret = 1;
		return ;
	}
	getinstance()->dummy_out = dup(STDOUT_FILENO);
	dup2(getinstance()->fdout, STDOUT);
}

void	child_double_input(char *cmd, int pip_out)
{
	char	*line;

	while (1)
	{	
		signal(SIGINT, heredoc_sig_handler);
		line = readline("heredoc> ");
		if (ft_strncmp(line, cmd, ft_strlen(cmd)))
		{
			write(pip_out, line, ft_strlen(line));
			free(line);
			write(pip_out, "\n", 1);
		}
		else
		{	
			free(line);
			exit(0);
		}
	}
}

void	double_input(char *cmd, t_node *token, t_node *next)
{
	int		pip[2];
	int		pid;
	int		status;

	getinstance()->yes_insert = 1;
	pipe(pip);
	pid = fork();
	if (pid == 0)
	{
		close(pip[0]);
		child_double_input(cmd, pip[1]);
	}
	else
	{
		signal(SIGINT, SIG_IGN);
		waitpid(pid, &status, 0);
		signal(SIGINT, signal_handler);
		close(pip[1]);
		getinstance()->dummy_in = dup(STDIN_FILENO);
		dup2(pip[0], STDIN);
		if (token != next)
			fd_read_and_write(STDIN, STDOUT);
	}
}

void	input(t_node *token)
{
	int	fd;

	getinstance()->yes_insert = 1;
	ft_close(getinstance()->fdin);
	fd = open(token->str, O_RDONLY, 0644);
	getinstance()->fdin = fd;
	if (getinstance()->fdin == -1)
	{
		print_err_massage(token->str, "Invalid file");
		getinstance()->ret = 1;
		return ;
	}
	getinstance()->dummy_in = dup(STDIN_FILENO);
	dup2(getinstance()->fdin, STDIN);
}
