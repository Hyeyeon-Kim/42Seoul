/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 21:03:24 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2021/07/19 01:13:28 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		do_pa(t_lists *lists)
{
	t_node		*a;
	t_node		*b;

	if (lists->b_arr->next == NULL)
		return ;
	a = lists->a_arr;
	b = lists->b_arr->next;
	push_front(a, b->value);
	pop_front(lists->b_arr);
	ft_putstr_fd("pa\n", 1);
}

void		do_pb(t_lists *lists)
{
	t_node		*a;
	t_node		*b;

	if (lists->a_arr->next == NULL)
		return ;
	a = lists->a_arr->next;
	b = lists->b_arr;
	push_front(b, a->value);
	pop_front(lists->a_arr);
	ft_putstr_fd("pb\n", 1);
}

void		do_ra(t_lists *lists)
{
	t_node		*a;

	if (lists->a_arr->next == NULL)
		return ;
	a = lists->a_arr->next;
	push_back(a, a->value);
	pop_front(lists->a_arr);
	ft_putstr_fd("ra\n", 1);
}

void		do_rb(t_lists *lists)
{
	t_node		*b;

	if (lists->b_arr->next == NULL)
		return ;
	b = lists->b_arr->next;
	push_back(b, b->value);
	pop_front(lists->b_arr);
	ft_putstr_fd("rb\n", 1);
}

void		do_rr(t_lists *lists)
{
	t_node		*a;
	t_node		*b;

	if (lists->b_arr->next == NULL)
		return ;
	if (lists->a_arr->next == NULL)
		return ;
	a = lists->a_arr->next;
	b = lists->b_arr->next;
	push_back(b, b->value);
	pop_front(lists->b_arr);
	push_back(a, a->value);
	pop_front(lists->a_arr);
	ft_putstr_fd("rr\n", 1);
}
