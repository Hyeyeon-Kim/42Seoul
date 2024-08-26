/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 04:44:35 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/02/12 16:11:05 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**insert_cmd(t_node *token, int cnt)
{
	char	**cmd;
	t_node	*temp;
	int		i;

	cmd = malloc(sizeof(char *) * cnt);
	if (!cmd)
		return (NULL);
	temp = token->next;
	cmd[0] = token->str;
	i = 1;
	while (temp && temp->type < TRUNC)
	{
		cmd[i++] = temp->str;
		temp = temp->next;
	}
	cmd[i] = NULL;
	return (cmd);
}

char	**get_cmd(t_node *token)
{
	t_node	*temp;
	int		cnt;

	if (!token)
		return (NULL);
	temp = token->next;
	cnt = 2;
	while (temp && temp->type < TRUNC)
	{
		temp = temp->next;
		cnt++;
	}
	return (insert_cmd(token, cnt));
}
