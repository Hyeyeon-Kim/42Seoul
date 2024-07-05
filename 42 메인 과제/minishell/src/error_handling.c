/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:34:09 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/02/12 17:34:10 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	error_handling(int num)
{
	printf("num = %d\n", num);
}

void	buffer_rollback(char *ptr)
{
	all_free(getinstance()->head);
	free(ptr);
}
