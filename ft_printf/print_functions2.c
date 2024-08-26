/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:12:20 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2024/07/05 14:12:25 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned(va_list ap)
{
	int				i;
	int				l;
	char			str[10];
	unsigned int	n;

	l = 0;
	n = va_arg(ap, unsigned int);
	if (n == 0)
		return (unsigned_zero());
	while (n > 0)
	{
		str[l] = n % 10 + '0';
		n /= 10;
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

int	print_hexadecimal(va_list ap, const char *arg)
{
	unsigned int	res;
	int				len;

	res = va_arg(ap, unsigned int);
	len = write_hex(res, arg);
	return (len);
}

int	unsigned_zero(void)
{
	if (write (1, "0", 1) == -1)
		return (-1);
	return (1);
}
