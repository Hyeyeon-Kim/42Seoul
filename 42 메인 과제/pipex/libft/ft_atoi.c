/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 21:06:01 by hyeykim           #+#    #+#             */
/*   Updated: 2021/07/19 01:07:09 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

long long	ft_atoi(const char *str)
{
	int			minus;
	long long	num;

	minus = 1;
	num = 0;
	while (*str >= 9 & *str <= 13 || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = ((num * 10) + (*str - '0') * minus);
		if (minus == 1 && num < 0)
			return (-1);
		else if (minus == -1 && num > 0)
			return (0);
		str++;
	}
	return (num);
}
