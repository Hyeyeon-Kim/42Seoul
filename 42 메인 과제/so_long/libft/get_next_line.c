/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 20:30:35 by hyeykim           #+#    #+#             */
/*   Updated: 2022/02/05 01:11:51 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_enter(char	*str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	str_split(char **str, char **line, int enter_pos)
{
	char		*temp;

	*line = ft_substr(*str, 0, enter_pos);
	temp = ft_substr(*str, enter_pos + 1, ft_strlen(*str) - enter_pos);
	free(*str);
	*str = temp;
	return (1);
}

int	return_str(char **str, char **line, int n)
{
	int			len;

	if (*str == 0)
	{
		*line = ft_substr("", 0, 0);
		return (0);
	}
	if (n < 0)
		return (-1);
	len = find_enter(*str);
	if (*str && len >= 0)
		return (str_split(str, line, len));
	*line = *str;
	*str = 0;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*str[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			n;
	int			enter_pos;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	n = read(fd, buf, BUFFER_SIZE);
	while (n > 0)
	{
		buf[n] = '\0';
		str[fd] = ft_strjoin(str[fd], buf);
		enter_pos = find_enter(str[fd]);
		if (enter_pos >= 0)
			return (str_split(&str[fd], line, enter_pos));
		n = read(fd, buf, BUFFER_SIZE);
	}
	return (return_str(&str[fd], line, n));
}
