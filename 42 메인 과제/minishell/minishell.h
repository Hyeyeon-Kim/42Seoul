/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:33:21 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/02/14 22:21:54 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <signal.h>
# include <fcntl.h>
# include <errno.h>
# include <readline/history.h>
# include <readline/readline.h>
# include "libft/libft.h"

# define EMPTY 0
# define CMD 1
# define ARG 2
# define TRUNC 3
# define APPEND 4
# define INPUT 5
# define DDINPUT 6
# define PIPE 7
# define END 8

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define SKIP 1
# define NOSKIP 0 

typedef struct s_node
{
	char			*str;
	int				type;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef struct s_data
{
	char			**path;
	char			**env;
	t_node			*head;
	int				yes_insert;
	int				dummy_in;
	int				dummy_out;
	int				fdin;
	int				fdout;
	int				pipin;
	int				pipout;
	int				ret;
	int				pid;
}					t_data;

void	execve_sig_handler(int signal);
void	signal_handler(int num);
void	set_signal(void);
void	heredoc_sig_handler(int signal);

void	rl_replace_line(const char *buffer, int something);
t_data	*getinstance(void);
void	init_data(void);
void	parse(char *str);
int		check_white_space(char *str);
t_node	*create_node(char *str);
t_node	*find_back(t_node *lst);
int		push_back(t_node *head, char *str);
void	pop_front(t_node *head);
void	pop_back(t_node *head);
int		list_cnt(t_node *head);
void	all_free(t_node *head);
void	error_handling(int num);
void	exec_process(void);
void	buffer_rollback(char *ptr);
int		parse_checker(char *ptr);
int		parse_checker2(char *ptr);
char	*parse_word(char *str);
int		parse_str(char *str);
char	*check_quotes(char *str, int quotes, int rm_quotes);
char	*change_env(char *str, int idx);
void	check_quotes_sub(char *str, int index, int *quotes, int *rm_quotes);
void	check_env(char **result, int idx);
char	*check_quotes(char *str, int quotes, int rm_quotes);
char	*get_envp_data(char *str);
char	*change_word(char *str, char *sub_str, int start, int end);
char	*change_str_env(char *str, int start, int end);

void	all_print(t_node *head);
void	minishell(void);
void	exec_cmd(t_node *token, int pip);
void	set_envp(char **envps);
int		unset_env(char *str);
void	remove_envp(void);
void	add_export(char *str, char **new, int i);
int		check_key_value(char *str, char *envs);
int		check_export(char *str);

void	ft_cd(char **cmd);
void	ft_pwd(void);
void	ft_env(void);
void	ft_echo(char **cmd);
void	ft_exit(char **cmd);
void	repeat(char	**cmd);
int		is_built_in(char **cmd);

void	ridir_file_open(t_node *token, int flag);
void	double_input(char *cmd, t_node *token, t_node *next);
void	input(t_node *token);
void	fd_read_and_write(int read_fd, int write_fd);
void	ft_close(int fd);

int		minipipe(void);

void	token_type(t_node *token);
int		is_type(int type, t_node *token);

t_node	*next_sep(t_node *token, int skip);
t_node	*prev_sep(t_node *token, int skip);
void	redir_and_exec(t_node *token, int pipe);

char	**insert_cmd(t_node *token, int cnt);
char	**get_cmd(t_node *token);

void	print_err_massage(char *token1, char *err_msg);
void	print_errno_message(char *token1, char *token2, char *err_msg);

void	reset_fd(void);

void	set_path(void);
#endif