/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:13:23 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2024/07/05 14:13:24 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_len(unsigned long long num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

int	write_hex(unsigned long long num, const char *arg)
{
	char	*hex;
	char	str[16];
	int		len;
	int		i;

	if (*arg == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	len = hex_len(num);
	i = len - 1;
	while (i > -1)
	{
		str[i] = hex[num % 16];
		num /= 16;
		i--;
	}
	i = 0;
	while (i < len)
	{
		if (write (1, &(str[i]), 1) == -1)
			return (-1);
		i++;
	}
	return (len);
}

int	print_n(int n)
{
	int		i;
	int		l;
	char	str[10];

	i = 0;
	l = 0;
	while (n > 0)
	{
		str[i] = n % 10 + '0';
		n /= 10;
		i++;
		l++;
	}
	i = 1;
	while (i <= l)
	{
		if (write(1, &str[l - i], 1) == -1)
			return (-1);
		i++;
	}
	return (l);
}

int	ft_putnbr(int n)
{
	int	len;

	if (n == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
		return (11);
	}
	else if (n == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	else if (n < 0)
	{
		n *= -1;
		if (write(1, "-", 1) == -1)
			return (-1);
		len = print_n(n);
		return (len + 1);
	}
	else
		len = print_n(n);
	return (len);
}
