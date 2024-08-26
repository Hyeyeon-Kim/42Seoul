#include "pipex.h"

void	pop_front(t_node *head)
{
	t_node		*remove;

	remove = head->next;
	head->next = remove->next;
	if (remove->next != NULL)
		remove->next->prev = head;
	free(remove);
}

void	pop_back(t_node *head)
{
	t_node		*back;

	back = find_back(head);
	back->prev->next = NULL;
	free(back);
}

void	all_free(t_node *head)
{
	t_node		*ptr;
	t_node		*del;

	ptr = head->next;
	while (ptr != NULL)
	{
		del = ptr;
		ptr = ptr->next;
		free(del);
	}
	free(ptr);
}
