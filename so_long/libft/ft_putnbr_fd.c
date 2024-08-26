/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:42:54 by hyeykim           #+#    #+#             */
/*   Updated: 2022/02/12 16:30:41 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	writenbr(int n, int fd)
{
	int		i;
	char	nbr[11];

	i = 11;
	while (i-- >= 0)
	{
		nbr[i] = n % 10 + '0';
		n /= 10;
		if (n == 0)
		{
			while (i <= 10)
			{
				write(fd, &nbr[i], 1);
				i++;
			}
			break ;
		}
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	writenbr(n, fd);
}
