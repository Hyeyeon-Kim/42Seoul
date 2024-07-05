/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2345.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 22:08:08 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2021/07/19 01:13:56 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_2(t_lists *stack, char name)
{
	t_node	*tmp;

	tmp = (name == 'a') ? stack->a_arr->next : stack->b_arr->next;
	if (name == 'a' && tmp->value > tmp->next->value)
		do_sa(stack);
	else if (name == 'b' && tmp->value < tmp->next->value)
		do_sb(stack);
}

void		sort_3(t_lists *stack, char name)
{
	(name == 'a') ? find_big(stack, 'a') : find_small(stack, 'b');
	(name == 'a') ? move_end(stack, 'a', 2) : move_end(stack, 'b', 1);
	while (name == 'a' && stack->big_r >= 1 && stack->big_r < 3)
	{
		do_ra(stack);
		stack->big_r--;
	}
	while (name == 'b' && stack->small_r >= 1 && stack->small_r < 3)
	{
		do_rb(stack);
		stack->small_r--;
	}
	name == 'a' ? sort_2(stack, 'a') : sort_2(stack, 'b');
	stack->big_r = 0;
	stack->small_r = 0;
}

void		sort_4(t_lists *stack)
{
	t_node	*tmp;

	tmp = stack->a_arr->next;
	find_big_small(stack, 'a');
	while (stack->small != tmp->value)
	{
		stack->small_r++;
		tmp = tmp->next;
	}
	while (stack->small_r > 0 && stack->small_r != 3)
	{
		do_ra(stack);
		stack->small_r--;
	}
	if (stack->small_r == 3)
		do_rra(stack);
	stack->small_r = 0;
	do_pb(stack);
	sort_3(stack, 'a');
	do_pa(stack);
}

void		sort_5(t_lists *stack)
{
	t_node	*tmp;
	int		mid;
	int		i;

	tmp = stack->a_arr->next;
	find_mid(stack, 'a', 5);
	mid = stack->mid;
	i = 0;
	while (i < stack->size)
	{
		if (tmp->value < mid)
			do_pb(stack);
		else
			do_ra(stack);
		tmp = tmp->next;
		i++;
	}
	sort_3(stack, 'a');
	sort_2(stack, 'b');
	do_pa(stack);
	do_pa(stack);
}
