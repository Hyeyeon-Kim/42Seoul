/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:25:16 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/02/12 17:26:31 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_data	*getinstance(void)
{
	static t_data	data;

	return (&data);
}

void	init_data(void)
{
	t_data	*ptr;

	ptr = getinstance();
	ptr->path = NULL;
	if (ptr->head == NULL)
		ptr->head = create_node(NULL);
}
