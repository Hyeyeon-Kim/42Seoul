/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_triple_strjoin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 04:29:58 by hyeykim           #+#    #+#             */
/*   Updated: 2022/02/12 17:05:25 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_triple_strjoin(char *s1, char *s2, char *s3)
{
	char	*str;
	char	*str2;

	if (s1 == 0 || s2 == 0 || s3 == 0)
		return (0);
	str = ft_strjoin(s1, s2);
	str2 = ft_strjoin(str, s3);
	free(str);
	return (str2);
}
