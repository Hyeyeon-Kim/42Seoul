#include "pipex.h"

t_node	*create_node(char *str)
{
	t_node		*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	// new_node->type = 0;
	new_node->str = str;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_node	*find_back(t_node *head)
{
	t_node		*lst;

	lst = head;
	while (lst->next != NULL)
	{
		lst = lst->next;
	}	
	return (lst);
}

int	push_back(t_node *head, char *str)
{
	t_node		*new_node;
	t_node		*back;

	new_node = create_node(str);
	if (!new_node)
		return (1);
	back = find_back(head);
	back->next = new_node;
	new_node->prev = back;
	return (0);
}