/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:33:39 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/02/12 17:33:39 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_white_space(char *str)
{
	int	i;
	int	ck;
	int	space;

	i = 0;
	ck = 0;
	space = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == '\r' || str[i] == '\v' || \
		str[i] == '\t' || str[i] == '\f')
			ck = 1;
		if (str[i] == ' ')
			space++;
		i++;
	}
	if (ck == 1 || space == ft_strlen(str))
		return (0);
	return (1);
}

int	parse_checker(char *ptr)
{
	int	i;
	int	single_cnt;
	int	double_cnt;

	i = 0;
	single_cnt = 0;
	double_cnt = 0;
	while (ptr[i])
	{
		if (ptr[i] == '\'')
			single_cnt++;
		if (ptr[i] == '"')
			double_cnt++;
		i++;
	}
	if (single_cnt % 2 == 1 || double_cnt % 2 == 1)
		return (1);
	return (0);
}
