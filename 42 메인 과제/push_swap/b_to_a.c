/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 22:26:31 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2021/07/19 01:13:27 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	command_cnt_b(t_com *com, t_lists *stack, int len, t_node *tmp_b)
{
	int		i;

	i = 0;
	while (++i <= len)
	{
		tmp_b = stack->b_arr->next;
		if (tmp_b->value < stack->min_pivot)
		{
			com->rb++;
			do_rb(stack);
		}
		else
		{
			com->pa++;
			do_pa(stack);
			if (stack->a_arr->next->value < stack->max_pivot)
			{
				com->ra++;
				do_ra(stack);
			}
		}
	}
}

void	sort_b_to_a(t_lists *stack, int len)
{
	t_com	com;

	if (len < 3)
	{
		if (len > 0)
		{
			if (len == 1)
				do_pa(stack);
			if (len == 2)
			{
				sort_2(stack, 'b');
				do_pa(stack);
				do_pa(stack);
			}
		}
		return ;
	}
	find_mid(stack, 'b', len);
	com_init(&com);
	command_cnt_b(&com, stack, len, stack->b_arr);
	sort_a_to_b(stack, com.pa - com.ra);
	reverse(&com, stack);
	sort_a_to_b(stack, com.ra);
	sort_b_to_a(stack, com.rb);
}
