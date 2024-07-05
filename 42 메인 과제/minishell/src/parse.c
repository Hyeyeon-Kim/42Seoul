/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:34:04 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/02/12 17:34:04 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	parse_checker2(char *str)
{
	int	check;
	int	idx;

	check = 0;
	idx = -1;
	while (str[++idx] != '\0')
	{
		if (str[idx] == '\'')
		{
			if (check == 0)
				check = 1;
			else if (check == 1)
				check = 0;
		}
		else if (str[idx] == '\"')
		{
			if (check == 0)
				check = 2;
			else if (check == 2)
				check = 0;
		}
	}
	if (check > 0)
		return (-1);
	return (1);
}

void	parse(char *str)
{
	if (parse_checker2(str) == -1)
		return ;
	if (parse_str(str) == -1)
		return ;
	if (list_cnt(getinstance()->head) == 0)
		return ;
	minishell();
}

void	first_check(char *str, int *index, int *quotes)
{
	*index = 0;
	*quotes = 0;
	if (str[*index] != '\'' && str[*index] != '\"')
		return ;
	if (str[*index] == '\'')
		*quotes = 1;
	else if (str[*index] == '\"')
		*quotes = 2;
	*index += 1;
}

char	*parse_word(char *str)
{
	int	idx;
	int	quotes;

	first_check(str, &idx, &quotes);
	while (str[idx] != '\0')
	{
		if (str[idx] == '\'')
		{
			if (quotes == 1)
				idx++;
			if (quotes != 2)
				break ;
		}
		else if (str[idx] == '\"')
		{
			if (quotes == 2)
				idx++;
			if (quotes != 1)
				break ;
		}
		if (str[idx] == ' ' && quotes == 0)
			break ;
		idx++;
	}
	return (ft_strndup(str, idx));
}

int	parse_str(char *str)
{
	char	*word;
	char	*result;
	int		idx;
	int		add;

	idx = 0;
	word = 0;
	add = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] == ' ')
		{
			add = 0;
			idx++;
			continue ;
		}
		word = parse_word(str + idx);
		idx += ft_strlen(word);
		result = check_quotes(word, 0, 0);
		free(word);
		push_back(getinstance()->head, result);
	}
	return (0);
}
