/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_read_and_write.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsong <dsong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:44:23 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/02/15 01:27:49 by dsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	fd_read_and_write(int read_fd, int write_fd)
{
	char	*line;
	char	*temp;
	int		len;

	len = 0;
	line = NULL;
	while (get_next_line(read_fd, &line) == 1)
	{
		temp = ft_strjoin(line, "\n");
		free(line);
		line = temp;
		len = ft_strlen(line);
		write(write_fd, line, len);
		free(line);
		line = NULL;
	}
}
