/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:23:07 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/02/12 17:23:35 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	pop_front(t_node *head)
{
	t_node		*remove;

	if (head == NULL || head->next == NULL)
		return ;
	remove = head->next;
	head->next = remove->next;
	if (remove->next != NULL)
		remove->next->prev = head;
	if (remove->str)
		free(remove);
	free(remove);
}

void	pop_back(t_node *head)
{
	t_node		*back;

	back = find_back(head);
	if (back == NULL || back->prev == NULL)
		return ;
	back->prev->next = NULL;
	if (back->str)
		free(back->str);
	free(back);
}

int	list_cnt(t_node *head)
{
	t_node	*node;
	int		cnt;

	cnt = 0;
	node = head->next;
	while (node != NULL)
	{
		cnt++;
		node = node->next;
	}
	return (cnt);
}

void	all_free(t_node *head)
{
	t_node		*ptr;
	t_node		*del;

	if (head == NULL)
		return ;
	ptr = head->next;
	while (ptr != NULL)
	{
		del = ptr;
		ptr = ptr->next;
		free(del->str);
		free(del);
	}
	head->next = NULL;
}
