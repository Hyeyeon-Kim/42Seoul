/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:36:46 by hyeykim           #+#    #+#             */
/*   Updated: 2021/07/19 01:13:45 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef	struct		s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef	struct		s_com
{
	int				sa;
	int				sb;
	int				ss;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				pa;
	int				pb;
	int				i;
	int				j;
	int				k;
}					t_com;

typedef struct		s_lists
{
	t_node			*a_arr;
	t_node			*b_arr;
	int				size;
	int				chk;
	int				a_size;
	int				b_size;
	int				big;
	int				small;
	int				big_rr;
	int				small_rr;
	int				big_r;
	int				small_r;
	int				mid;
	int				max_pivot;
	int				min_pivot;
	int				split_use;
	char			*prev_char;
}					t_lists;

t_node				*create_node(int value);
void				push_front(t_node *head, int value);
t_node				*find_back(t_node *lst);
int					push_back(t_node *head, int value);
void				pop_front(t_node *head);
void				pop_back(t_node *head);
void				print_arr(t_node *head);
void				do_sa(t_lists *lists);
void				do_sb(t_lists *lists);
void				do_ss(t_lists *lists);
void				do_pa(t_lists *lists);
void				do_pb(t_lists *lists);
void				do_ra(t_lists *lists);
void				do_rb(t_lists *lists);
void				do_rr(t_lists *lists);
void				do_rra(t_lists *lists);
void				do_rrb(t_lists *lists);
void				do_rrr(t_lists *lists);
int					overlap(t_node *head, t_node *back, int num);
void				all_free(t_node *head);
int					error_check(char**argv, t_lists *stack);
void				sort(t_lists *stack);
void				sort_b_to_a(t_lists *stack, int len);
void				sort_a_to_b(t_lists *stack, int len);
void				sort_2(t_lists *stack, char name);
void				sort_3(t_lists *stack, char name);
void				sort_4(t_lists *stack);
void				sort_5(t_lists *stack);
int					error_check(char**argv, t_lists *stack);
void				push_swap_error(t_lists *stack);
int					init(t_lists *stack);
int					list_len(t_node *arr);
void				find_small(t_lists *stack, char name);
void				find_big(t_lists *stack, char name);
void				find_big_small(t_lists *stack, char name);
void				find_mid(t_lists *stack, char name, int len);
void				move_end(t_lists *stack, char name, int flag);
int					sorted(t_node *arr, int len);
char				**if_one_str(char *str, t_lists *stack);
void				arr_sorting(int *str, int len);
void				com_init(t_com *com);
void				reverse(t_com *com, t_lists *stack);
#endif
