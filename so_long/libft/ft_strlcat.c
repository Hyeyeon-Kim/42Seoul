/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 00:57:57 by hyeykim           #+#    #+#             */
/*   Updated: 2021/11/19 16:23:32 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dst, const char *src, int size)
{
	int	i;
	int	j;
	int	des_len;
	int	src_len;

	des_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	j = des_len;
	while ((src[i] != '\0') && i + j + 1 < size)
	{
		dst[j + i] = src[i];
		i++;
	}
	dst[j + i] = '\0';
	if (des_len > size)
		return (src_len + size);
	else
		return (des_len + src_len);
}
