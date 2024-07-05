#include "pipex.h"

t_data	*getinstance(void)
{
	static t_data	data;

	return &data;
}

void	init_data(void)
{
	t_data	*ptr;
	
	ptr = getinstance();
    ptr->path = NULL;
	ptr->head = create_node(NULL);
	// printf("ch %p %p\n", ptr->head->next, ptr->head->prev);
	ptr->token_cnt = 4;//임시로 지정했음
}