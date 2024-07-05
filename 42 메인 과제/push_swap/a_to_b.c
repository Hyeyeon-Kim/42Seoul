/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 22:26:35 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2021/07/19 01:13:26 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	com_init(t_com *com)
{
	com->ra = 0;
	com->pb = 0;
	com->rb = 0;
	com->pa = 0;
	com->i = 0;
}

void	reverse(t_com *com, t_lists *stack)
{
	int		j;
	int		k;

	k = 0;
	j = 0;
	while (com->ra > j && com->rb > j)
	{
		do_rrr(stack);
		j++;
	}
	while (k < (com->ra - j))
	{
		do_rra(stack);
		k++;
	}
	while (k < (com->rb - j))
	{
		do_rrb(stack);
		k++;
	}
}

void	command_cnt(t_com *com, t_lists *stack, int len, t_node *tmp_a)
{
	while (++(com->i) <= len)
	{
		tmp_a = stack->a_arr->next;
		if (tmp_a->value >= stack->max_pivot)
		{
			com->ra++;
			do_ra(stack);
		}
		else
		{
			com->pb++;
			do_pb(stack);
			if (stack->b_arr->next->value >= stack->min_pivot)
			{
				com->rb++;
				do_rb(stack);
			}
		}
	}
}

void	sort_a_to_b(t_lists *stack, int len)
{
	t_com	com;

	if (len < 3)
	{
		sort_2(stack, 'a');
		return ;
	}
	if (sorted(stack->a_arr, len))
		return ;
	find_mid(stack, 'a', len);
	com_init(&com);
	command_cnt(&com, stack, len, stack->a_arr);
	reverse(&com, stack);
	sort_a_to_b(stack, com.ra);
	sort_b_to_a(stack, com.rb);
	sort_b_to_a(stack, com.pb - com.rb);
}
