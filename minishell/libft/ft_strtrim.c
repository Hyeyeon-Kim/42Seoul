/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 05:57:27 by hyeykim           #+#    #+#             */
/*   Updated: 2022/02/12 16:46:36 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		end;
	char	*str;

	if (s1 == 0 || set == 0)
		return (0);
	i = 0;
	end = ft_strlen(s1);
	while (s1[i] && is_in_set(s1[i], set))
		i++;
	while (end > i && is_in_set(s1[end - 1], set))
		end--;
	str = (char *)malloc(end - i + 1);
	if (!str)
		return (0);
	j = 0;
	while (s1[i + j] && i + j < end)
	{
		str[j] = s1[i + j];
		j++;
	}
	str[j] = 0;
	return (str);
}
