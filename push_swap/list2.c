/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 22:03:55 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2021/11/12 03:29:30 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pop_front(t_node *head)
{
	t_node		*remove;

	remove = head->next;
	head->next = remove->next;
	if (remove->next != NULL)
		remove->next->prev = head;
	free(remove);
}

void	pop_back(t_node *head)
{
	t_node		*back;

	back = find_back(head);
	back->prev->next = NULL;
	free(back);
}

void	all_free(t_node *head)
{
	t_node		*ptr;
	t_node		*del;

	ptr = head->next;
	while (ptr != NULL)
	{
		del = ptr;
		ptr = ptr->next;
		free(del);
	}
	free(ptr);
}
