/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:33:44 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/02/12 17:33:45 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*change_env(char *str, int idx)
{
	int		index;
	char	*result;

	index = idx + 1;
	while (str[index] && str[index] != ' ' \
			&& str[index] != '\'' && str[index] != '\"')
	{
		if (str[index - 1] == '$')
		{
			if (str[index] == '$' || str[index] == '?')
			{
				index++;
				break ;
			}
		}
		index++;
	}
	result = change_str_env(str, idx, index);
	return (result);
}

void	check_quotes_sub(char *str, int index, int *quotes, int *rm_quotes)
{
	if (str[index] == '\'')
	{
		if (*quotes == 0)
			*quotes = 1;
		else if (*quotes == 1)
			*quotes = 0;
		*rm_quotes = 1;
	}
	else if (str[index] == '\"')
	{
		if (*quotes == 0)
			*quotes = 2;
		else if (*quotes == 2)
			*quotes = 0;
		*rm_quotes = 1;
	}
}

void	check_env(char **result, int idx)
{
	char	*temp;

	temp = change_env(*result, idx);
	free(*result);
	*result = temp;
}

char	*check_quotes(char *str, int quotes, int rm_quotes)
{
	char	*result;
	char	*data;
	int		idx;

	result = ft_strdup(str);
	idx = 0;
	while (result[idx] != '\0')
	{
		check_quotes_sub(result, idx, &quotes, &rm_quotes);
		if (result[idx] == '$' && quotes != 1)
			check_env(&result, idx);
		idx++;
	}
	if (rm_quotes == 1)
	{
		data = ft_strndup(result + 1, ft_strlen(result) - 2);
		free(result);
		result = data;
	}
	return (result);
}
