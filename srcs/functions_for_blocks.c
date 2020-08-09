
#include "push_swap.h"

t_block			*new_block(void)
{
	t_block	*new;

	if (!(new = (t_block *)malloc(sizeof(t_block))))
		return (NULL);
	new->next = NULL;
	return (new);
}

t_block			*add_new_block(t_block *block, t_block *new)
{
	new->next = block;
	block = new;
	return (block);
}

void			remove_one_block(t_pushswap *head)
{
	t_block *help;

	help = head->block->next;
	free(head->block);
	head->block = help;
}

void			fill_block(t_block *block, int start, int count)
{
	block->start = start;
	block->end = start + count - 1;
	block->count = count;
}

void			get_block(t_pushswap *head, int start, int count)
{
	t_block		*new;

	new = new_block();
	if (head->block != NULL)
		head->block = add_new_block(head->block, new);
	else
		head->block = new;
	fill_block(head->block, start, count);
}
