/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:14:39 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/02/12 16:46:17 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			index;
	unsigned char	*cp1;
	unsigned char	*cp2;

	cp1 = (unsigned char *)s1;
	cp2 = (unsigned char *)s2;
	index = 0;
	while (cp1[index] != '\0' && index < n)
	{
		if (cp1[index] != cp2[index])
			return (cp1[index] - s2[index]);
		index++;
	}
	if (cp1[index] == '\0' && index < n)
		return (cp1[index] - cp2[index]);
	return (0);
}
