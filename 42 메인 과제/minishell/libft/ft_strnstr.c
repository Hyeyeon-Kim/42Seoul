/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 00:58:20 by hyeykim           #+#    #+#             */
/*   Updated: 2022/02/12 16:30:16 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *c, const char *needle, int len)
{
	int		i;
	int		j;
	char	*find;

	find = (char *)c;
	i = 0;
	if (needle[i] == 0)
		return (find);
	while (find[i] && i < len)
	{
		j = 0;
		while (find[i + j] == needle[j] && i + j < len)
		{
			if (needle[j + 1] == 0)
				return (&find[i]);
			j++;
		}
		i++;
	}
	return (0);
}
