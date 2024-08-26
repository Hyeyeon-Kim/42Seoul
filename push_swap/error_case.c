/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 22:15:37 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2021/07/19 01:13:39 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		error_check(char **argv, t_lists *stack)
{
	int			i;
	int			j;
	long long	num;

	i = stack->split_use;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (j == 0 && (argv[i][0] == '-' || argv[i][j] == '+'))
				j++;
			if (!(ft_isdigit(argv[i][j])))
				return (1);
			j++;
		}
		num = ft_atoi(argv[i]);
		if (num > 2147483647 || num < -2147483648)
			return (1);
		if (push_back(stack->a_arr, (int)num))
			return (1);
		i++;
	}
	stack->size = i - 1;
	return (0);
}

void	push_swap_error(t_lists *stack)
{
	ft_putstr_fd("Error\n", 1);
	all_free(stack->a_arr);
	all_free(stack->b_arr);
	exit(0);
}
