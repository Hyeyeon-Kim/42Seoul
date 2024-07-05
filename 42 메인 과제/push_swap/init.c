/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 22:18:28 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2021/07/19 01:13:41 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		init(t_lists *stack)
{
	stack->a_arr = create_node(0);
	if (stack->a_arr == NULL)
		return (0);
	stack->b_arr = create_node(0);
	if (stack->b_arr == NULL)
		return (0);
	stack->size = 0;
	stack->big = 0;
	stack->small = 0;
	stack->big_rr = 0;
	stack->small_rr = 0;
	stack->big_r = 0;
	stack->small_r = 0;
	stack->mid = 0;
	stack->split_use = 1;
	stack->a_size = 0;
	stack->b_size = 0;
	stack->prev_char = "  ";
	stack->chk = 0;
	return (1);
}

int		list_len(t_node *arr)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = arr;
	while (tmp->next != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	move_end(t_lists *stack, char name, int flag)
{
	t_node	*tmp;
	int		target;

	tmp = (name == 'a') ? stack->a_arr->next : stack->b_arr->next;
	target = (flag == 1) ? stack->small : stack->big;
	while (tmp->value != target)
	{
		(flag == 1) ? stack->small_r++ : stack->big_r++;
		tmp = tmp->next;
	}
	(flag == 1) ? stack->small_r++ : stack->big_r++;
}

int		sorted(t_node *arr, int len)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = arr->next;
	while (tmp->next != NULL && len > i)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

char	**if_one_str(char *str, t_lists *stack)
{
	char	**arr;
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (i != 0 && str[i] == ' ')
		{
			flag = 1;
			stack->split_use = 0;
			break ;
		}
		i++;
	}
	if (flag)
		return (arr = ft_split(str, ' '));
	else
		return (NULL);
}
