/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 21:53:47 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2021/07/19 01:13:29 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		do_sa(t_lists *lists)
{
	t_node		*a_node1;
	t_node		*a_node2;
	int			tmp;

	if (lists->a_arr->next == NULL)
		return ;
	a_node1 = lists->a_arr->next;
	a_node2 = a_node1->next;
	tmp = a_node1->value;
	a_node1->value = a_node2->value;
	a_node2->value = tmp;
	ft_putstr_fd("sa\n", 1);
}

void		do_sb(t_lists *lists)
{
	t_node		*b_node1;
	t_node		*b_node2;
	int			tmp;

	if (lists->b_arr->next == NULL)
		return ;
	b_node1 = lists->b_arr->next;
	b_node2 = b_node1->next;
	tmp = b_node1->value;
	b_node1->value = b_node2->value;
	b_node2->value = tmp;
	ft_putstr_fd("sb\n", 1);
}

void		do_ss(t_lists *lists)
{
	t_node		*a_node1;
	t_node		*a_node2;
	t_node		*b_node1;
	t_node		*b_node2;
	int			tmp;

	if (lists->a_arr->next == NULL)
		return ;
	if (lists->b_arr->next == NULL)
		return ;
	a_node1 = lists->a_arr->next;
	a_node2 = a_node1->next;
	tmp = a_node1->value;
	a_node1->value = a_node2->value;
	a_node2->value = tmp;
	b_node1 = lists->b_arr->next;
	b_node2 = b_node1->next;
	tmp = b_node1->value;
	b_node1->value = b_node2->value;
	b_node2->value = tmp;
	ft_putstr_fd("ss\n", 1);
}
