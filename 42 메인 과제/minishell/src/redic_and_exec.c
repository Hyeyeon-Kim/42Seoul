/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redic_and_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsong <dsong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 04:38:57 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/02/15 00:58:13 by dsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_node	*next_sep(t_node *token, int skip)
{
	if (token && skip)
		token = token->next;
	while (token && token->type < TRUNC)
		token = token->next;
	return (token);
}

t_node	*prev_sep(t_node *token, int skip)
{
	if (token && skip)
		token = token->prev;
	while (token && token->type < TRUNC && token != getinstance()->head)
		token = token->prev;
	return (token);
}

void	redir_and_exec(t_node *token, int pipe)
{
	t_node	*prev;
	t_node	*next;

	prev = prev_sep(token, NOSKIP);
	next = next_sep(token, NOSKIP);
	if (is_type(TRUNC, prev))
		ridir_file_open(token, O_CREAT | O_WRONLY | O_TRUNC);
	else if (is_type(APPEND, prev))
		ridir_file_open(token, O_CREAT | O_WRONLY | O_APPEND);
	else if (is_type(DDINPUT, prev))
		double_input(token->str, token, next);
	else if (is_type(INPUT, prev))
		input(token);
	else if (is_type(PIPE, prev))
		pipe = minipipe();
	if (getinstance()->ret)
		return ;
	if (next && pipe != 1 && token != next && next->next)
		redir_and_exec(next->next, pipe);
	if ((is_type(PIPE, prev) || prev == getinstance()->head) && pipe != 1)
		exec_cmd(token, pipe);
}
