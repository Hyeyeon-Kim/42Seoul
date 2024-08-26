/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_triple_strjoin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 04:29:58 by hyeykim           #+#    #+#             */
/*   Updated: 2021/11/12 17:11:10 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_triple_strjoin(char const *s1, char const *s2, char const *s3)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	if (s1 == 0 || s2 == 0 || s3 == 0)
		return (0);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1));
	if (!str)
		return (0);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	k = 0;
	while (s3[k])
	{
		str[i + j + k] = s3[k];
		k++;
	}
	str[i + j + k] = 0;
	return (str);
}
