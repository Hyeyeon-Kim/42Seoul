/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:37:08 by hyeykim           #+#    #+#             */
/*   Updated: 2021/11/12 03:31:38 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node		*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	push_front(t_node *head, int value)
{
	t_node		*new_node;
	t_node		*head_next;

	head_next = head->next;
	new_node = create_node(value);
	if (!new_node)
		return ;
	new_node->next = head->next;
	head->next = new_node;
	new_node->prev = head;
	if (head_next != NULL)
		new_node->next->prev = new_node;
}

t_node	*find_back(t_node *head)
{
	t_node		*lst;

	lst = head;
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	overlap(t_node *head, t_node *back, int num)
{
	t_node		*pos;

	pos = back;
	while (pos != head)
	{
		if (pos->value == num)
			return (1);
		pos = pos->prev;
	}
	return (0);
}

int	push_back(t_node *head, int value)
{
	t_node		*new_node;
	t_node		*back;

	new_node = create_node(value);
	if (!new_node)
		return (1);
	back = find_back(head);
	if (overlap(head, back, value))
		return (1);
	back->next = new_node;
	new_node->prev = back;
	return (0);
}
