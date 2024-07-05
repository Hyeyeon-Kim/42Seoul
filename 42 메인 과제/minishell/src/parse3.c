/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:33:49 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/02/12 17:33:50 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_envp_data(char *str)
{
	int		i;
	int		len;

	i = 0;
	while (getinstance()->env[i])
	{
		len = check_key_value(str, getinstance()->env[i]);
		if (len != 0)
			return (ft_strdup(&getinstance()->env[i][len + 1]));
		i++;
	}
	return (0);
}

char	*change_word(char *str, char *sub_str, int start, int end)
{
	char	*front;
	char	*temp;
	char	*back;

	front = ft_strndup(str, start);
	back = ft_strdup(str + end);
	temp = ft_strjoin(front, sub_str);
	free(front);
	front = temp;
	temp = ft_strjoin(front, back);
	free(front);
	free(back);
	front = temp;
	return (front);
}

char	*change_str_env(char *str, int start, int end)
{
	char	*target;
	char	*data;
	char	*result;

	target = ft_strndup(str + start + 1, end - start - 1);
	data = get_envp_data(target);
	if (data == NULL)
	{
		if (ft_strlen(target) == 0)
			data = ft_strdup("$");
		else if (ft_strlen(target) == 1 && target[0] == '?')
			data = ft_itoa(getinstance()->ret);
		else if (ft_strlen(target) == 1 && target[0] == '$')
			data = ft_itoa(getpid());
		else
			data = ft_strdup("");
	}
	result = change_word(str, data, start, end);
	free(target);
	free(data);
	return (result);
}
