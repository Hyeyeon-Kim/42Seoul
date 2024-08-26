/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:36:39 by hyeykim           #+#    #+#             */
/*   Updated: 2021/07/19 01:35:45 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		arr_sorting(int *str, int len)
{
	int		tmp;
	int		i;

	tmp = 0;
	i = 0;
	while (i < len - 1)
	{
		if (str[i] <= str[i + 1])
			i++;
		else
		{
			tmp = str[i];
			str[i] = str[i + 1];
			str[i + 1] = tmp;
			i = 0;
		}
	}
}

void		sort(t_lists *stack)
{
	int		len;

	len = list_len(stack->a_arr);
	stack->size = len;
	if (!(sorted(stack->a_arr, len)))
	{
		if (len == 2)
			sort_2(stack, 'a');
		else if (len == 3)
			sort_3(stack, 'a');
		else if (len == 4)
			sort_4(stack);
		else if (len == 5)
			sort_5(stack);
		else
			sort_a_to_b(stack, len);
	}
}

int			right_case(t_lists *stack, int argc, char **argv)
{
	char	**s;

	if (!(init(stack)))
		stack->chk = 1;
	if (argc > 1)
	{
		s = if_one_str(argv[1], stack);
		argv = s != (void *)'\0' ? s : argv;
	}
	if (argc > 1)
		stack->chk = error_check(argv, stack);
	else
		stack->chk = 1;
	if (stack->chk)
	{
		ft_putstr_fd("Error\n", 1);
		all_free(stack->a_arr);
		free(stack->b_arr);
		return (0);
	}
	sort(stack);
	all_free(stack->a_arr);
	all_free(stack->b_arr);
	exit(0);
}

int			main(int argc, char **argv)
{
	t_lists	stack;

	if (argc != 1)
	{
		right_case(&stack, argc, argv);
	}
}
