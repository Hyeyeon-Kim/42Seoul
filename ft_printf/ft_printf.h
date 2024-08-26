/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:13:21 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2024/07/05 14:13:21 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *arg, ...);
int	write_arg(const char *arg, va_list ap);
int	find_type(const char *arg, va_list ap);
int	print_char(va_list ap);
int	print_str(va_list ap);
int	print_pointer(va_list ap);
int	print_decimal(va_list ap);
int	print_integer(va_list ap);
int	print_unsigned(va_list ap);
int	print_hexadecimal(va_list ap, const char *arg);
int	unsigned_zero(void);
int	hex_len(unsigned long long num);
int	write_hex(unsigned long long num, const char *arg);
int	print_n(int n);
int	ft_putnbr(int n);

#endif