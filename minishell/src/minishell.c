/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsong <dsong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 21:18:18 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/02/15 00:58:18 by dsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exec_bin(char **cmd)
{
	int		ret;
	char	*exec_path;
	int		i;

	ret = -1;
	i = 0;
	if (getinstance()->path != NULL)
	{
		ret = execve(cmd[0], cmd, getinstance()->env);
		while (ret == -1 && getinstance()->path[i])
		{
			exec_path = ft_triple_strjoin(getinstance()->path[i], "/", cmd[0]);
			ret = execve(exec_path, cmd, getinstance()->env);
			i++;
		}
	}
	print_err_massage(cmd[0], "command not found");
	exit(1);
}

void	exec_parent(void)
{
	int		status;

	if (getinstance()->yes_insert == 2)
	{
		close(getinstance()->pipin);
		close(getinstance()->pipout);
	}
	getinstance()->pid = 0;
	waitpid(-1, &status, 0);
}

void	exec_cmd_not_pipe_child(char **cmd)
{
	pid_t	pid;

	signal(SIGINT, execve_sig_handler);
	signal(SIGQUIT, execve_sig_handler);
	pid = fork();
	getinstance()->pid = pid;
	if (pid == 0)
	{
		if (getinstance()->yes_insert == 2)
			dup2(getinstance()->pipout, STDOUT);
		exec_bin(cmd);
	}
	else if (pid > 0)
		exec_parent();
}

void	exec_cmd(t_node *token, int pip)
{
	char	**cmd;

	cmd = get_cmd(token);
	if (is_built_in(cmd) == 0)
	{
		if (pip == 2)
			exec_bin(cmd);
		else
			exec_cmd_not_pipe_child(cmd);
		set_signal();
	}
	free(cmd);
}

void	minishell(void)
{
	t_node	*ptr;
	int		status;

	status = 0;
	ptr = getinstance()->head->next;
	while (ptr != NULL)
	{
		token_type(ptr);
		ptr = ptr->next;
	}
	getinstance()->yes_insert = 3;
	getinstance()->pid = 0;
	if (getinstance()->head->next->type < TRUNC)
		redir_and_exec(getinstance()->head->next, 0);
	else
		redir_and_exec(getinstance()->head->next->next, 0);
	waitpid(-1, &status, 0);
}
