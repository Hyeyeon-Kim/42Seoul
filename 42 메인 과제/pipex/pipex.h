#include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

# define EMPTY 0
# define CMD 1
# define ARG 2
# define TRUNC 3
# define APPEND 4
# define INPUT 5
# define PIPE 6
# define END 7

typedef	struct		s_node
{
	char			*str;
	int				type;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef	struct		s_data
{
	char			**path;
	t_node			*head;
	int				token_cnt;
}					t_data;

// list.c list2.c
t_node				*create_node(char *str);
t_node				*find_back(t_node *lst);
int					push_back(t_node *head, char *str);
void				pop_front(t_node *head);
void				pop_back(t_node *head);
void                all_free(t_node *head);

//data.c
t_data	*getinstance(void);
void	init_data(void);
