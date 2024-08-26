/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 22:11:41 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2021/07/19 01:13:40 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		find_small(t_lists *stack, char name)
{
	t_node	*tmp;

	tmp = (name == 'a') ? stack->a_arr->next : stack->b_arr->next;
	stack->small = tmp->value;
	while (tmp != NULL)
	{
		if (stack->small > tmp->value)
			stack->small = tmp->value;
		tmp = tmp->next;
	}
}

void		find_big(t_lists *stack, char name)
{
	t_node	*tmp;

	tmp = (name == 'a') ? stack->a_arr->next : stack->b_arr->next;
	while (tmp != NULL)
	{
		if (stack->big < tmp->value)
			stack->big = tmp->value;
		tmp = tmp->next;
	}
}

void		find_big_small(t_lists *stack, char name)
{
	find_big(stack, name);
	find_small(stack, name);
}

void		find_mid(t_lists *stack, char name, int len)
{
	t_node	*tmp;
	int		*str;
	int		i;

	if (stack == NULL)
		push_swap_error(stack);
	tmp = (name == 'a') ? stack->a_arr->next : stack->b_arr->next;
	if (!(str = (int *)malloc(sizeof(int) * (len + 1))))
		push_swap_error(stack);
	i = 0;
	while (i < len)
	{
		str[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	arr_sorting(str, len);
	stack->mid = str[len / 2];
	stack->min_pivot = str[len / 3];
	stack->max_pivot = str[(len / 3) * 2];
	free(str);
}
