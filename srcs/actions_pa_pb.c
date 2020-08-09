
#include "push_swap.h"

void		action_pa(t_pushswap *head)
{
	t_stack		*transfer;

	if (head->begin_b == NULL)
		return ;
	transfer = head->stack_b;
	head->begin_b = head->stack_b->next;
	transfer->next = head->begin_a;
	head->begin_a = transfer;
	head->stack_a = head->begin_a;
	head->stack_b = head->begin_b;
	head->opr++;
	if (head->program == PUSH_SWAP)
		ft_printf("pa\n");
}

void		action_pb(t_pushswap *head)
{
	t_stack		*transfer;

	if (head->begin_a == NULL)
		return ;
	transfer = head->stack_a;
	head->begin_a = head->stack_a->next;
	transfer->next = head->begin_b;
	head->begin_b = transfer;
	head->stack_b = head->begin_b;
	head->stack_a = head->begin_a;
	head->opr++;
	if (head->program == PUSH_SWAP)
		ft_printf("pb\n");
}
