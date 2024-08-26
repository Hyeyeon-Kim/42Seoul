/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 21:55:56 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2021/07/19 01:13:38 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		do_rra(t_lists *lists)
{
	t_node		*a;

	if (lists->a_arr->next == NULL)
		return ;
	a = find_back(lists->a_arr);
	push_front(lists->a_arr, a->value);
	pop_back(lists->a_arr);
	ft_putstr_fd("rra\n", 1);
}

void		do_rrb(t_lists *lists)
{
	t_node		*b;

	if (lists->b_arr->next == NULL)
		return ;
	b = find_back(lists->b_arr);
	push_front(lists->b_arr, b->value);
	pop_back(lists->b_arr);
	ft_putstr_fd("rrb\n", 1);
}

void		do_rrr(t_lists *lists)
{
	t_node		*a;
	t_node		*b;

	if (lists->a_arr->next == NULL)
		return ;
	if (lists->b_arr->next == NULL)
		return ;
	a = find_back(lists->a_arr);
	b = find_back(lists->b_arr);
	push_front(lists->a_arr, a->value);
	pop_back(lists->a_arr);
	push_front(lists->b_arr, b->value);
	pop_back(lists->b_arr);
	ft_putstr_fd("rrr\n", 1);
}
