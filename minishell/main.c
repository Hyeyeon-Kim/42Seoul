/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 21:17:10 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2024/07/05 14:14:43 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	reset_fd(void)
{
	if (getinstance()->yes_insert == 1)
	{
		close(getinstance()->fdin);
		dup2(getinstance()->dummy_in, STDIN_FILENO);
		close(getinstance()->dummy_in);
	}
	else if (getinstance()->yes_insert == 0)
	{
		close(getinstance()->fdout);
		dup2(getinstance()->dummy_out, STDOUT_FILENO);
		close(getinstance()->dummy_out);
	}
	else if (getinstance()->yes_insert == 2)
	{
		close(getinstance()->pipin);
		close(getinstance()->pipout);
		dup2(getinstance()->dummy_out, STDOUT_FILENO);
		close(getinstance()->dummy_out);
		dup2(getinstance()->dummy_in, STDIN_FILENO);
		close(getinstance()->dummy_in);
	}
}

void	set_path(void)
{
	char	**path;
	int		i;
	char	**env;

	free(getinstance()->path);
	path = NULL;
	env = getinstance()->env;
	i = 0;
	while (env[i])
	{
		if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T'\
		&& env[i][3] == 'H')
			path = ft_split(&env[i][5], ':');
		i++;
	}
	getinstance()->path = path;
}

void	print_prompt(char **str)
{
	free(*str);
	printf("\033[1A");
	printf("\033[10C");
	printf(" exit\n");
	exit(0);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	*str;

	init_data();
	set_envp(envp);
	set_path();
	getinstance()->ret = 0;
	argc = argv[0][0];
	set_signal();
	while (1)
	{
		str = readline("minishell>");
		if (!str)
			print_prompt(&str);
		else if (*str != '\0' && check_white_space(str))
		{
			parse(str);
			reset_fd();
			all_free(getinstance()->head);
			add_history(str);
		}
		free(str);
	}
	free(getinstance()->head);
	return (0);
}
