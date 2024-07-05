/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:09:33 by hyeykim           #+#    #+#             */
/*   Updated: 2021/11/19 16:24:02 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(int, char))
{
	char		*temp;
	int			i;

	i = 0;
	if (s == 0)
		return (0);
	temp = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (temp == NULL)
		return (0);
	while (s[i])
	{
		temp[i] = f(i, s[i]);
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
