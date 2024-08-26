/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:21:26 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/02/12 17:22:58 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_node	*create_node(char *str)
{
	t_node		*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->str = str;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_node	*find_back(t_node *head)
{
	t_node	*lst;

	if (head == NULL)
		return (NULL);
	lst = head;
	while (lst->next != NULL)
	{
		lst = lst->next;
	}	
	return (lst);
}

int	push_back(t_node *head, char *str)
{
	t_node		*new_node;
	t_node		*back;

	new_node = create_node(str);
	if (!new_node)
		return (1);
	back = find_back(head);
	if (back == NULL)
	{
		free(new_node);
		return (1);
	}
	back->next = new_node;
	new_node->prev = back;
	return (0);
}

void	all_print(t_node *head)
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
	}
}
