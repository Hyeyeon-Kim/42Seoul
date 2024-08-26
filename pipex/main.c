#include "pipex.h"

char cmd_line[4][10] = {"echo", "hi", ">", "data.txt"};
int cnt_token = 4;

char	**get_path(char **env)
{
	int		i;
	char	*s;

	i = 0;
	while (env[i])
	{
		s = env[i];
		if (s[0] == 'P' && s[1] == 'A' &&
			s[2] == 'T' && s[3] == 'H' &&
			s[4] == '=')
			{
			return (ft_split(&s[5], ':'));
			}
		i++;
	}
	return (NULL);
}


void token_type(t_node *token)
{
	if (ft_strcmp(token->str, "") == 0)
		token->type = EMPTY;
	else if (ft_strcmp(token->str, ">") == 0)
		token->type = TRUNC;
	else if (ft_strcmp(token->str, ">>") == 0)
		token->type = APPEND;
	else if (ft_strcmp(token->str, "<") == 0)
		token->type = INPUT;
	else if (ft_strcmp(token->str, "|") == 0)
		token->type = PIPE;
	else if (ft_strcmp(token->str, ";") == 0)
		token->type = END;
	else if (token->prev == NULL || token->prev->type >= TRUNC)
		token->type = CMD;
	else
		token->type = ARG;
}

void insert_token_list()
{
	//t_node *lst;
	int i;

	i = 0;
	while (i < getinstance()->token_cnt)
	{	
		push_back(getinstance()->head, cmd_line[i]);
		i++;
	}

	// lst = getinstance()->head;
	// while (lst->next == NULL)
	// {
	// 	printf("%s\n", lst->str);
	// 	lst = lst->next;
	// }	

}

int main(int argc, char **argv, char **env)
{
	argv = NULL;
	argc =  0;
	
	t_node *lst;
	t_node *head;

	init_data();
	getinstance()->path = get_path(env); //get_path: error나면 null로 반환
	head = getinstance()->head;
	insert_token_list();
	
	// lst = head->next;
	// while (lst->next == NULL)
	// {
	// 	token_type(lst);
	// 	lst = lst->next;
	// }	
	// int i;

	// i = 0;
	// while (i < getinstance()->token_cnt)
	// {	
	// 	push_back(&head, cmd_line[i]);
	// 	i++;
	// }

	lst = head->next;
	while (lst != NULL)
	{
		printf("%s\n", lst->str);
		lst = lst->next;
	}	

}