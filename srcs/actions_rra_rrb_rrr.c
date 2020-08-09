
#include "push_swap.h"

void		action_rra(t_pushswap *head)
{
	t_stack		*transfer;

	if (head->begin_a == NULL || head->begin_a->next == NULL)
		return ;
	while (head->stack_a->next->next)
		head->stack_a = head->stack_a->next;
	transfer = head->stack_a->next;
	head->stack_a->next = NULL;
	head->stack_a = head->begin_a;
	transfer->next = head->begin_a;
	head->begin_a = transfer;
	head->stack_a = head->begin_a;
	head->opr++;
	if (head->program == PUSH_SWAP && head->print == 1)
		ft_printf("rra\n");
}

void		action_rrb(t_pushswap *head)
{
	t_stack		*transfer;

	if (head->begin_b == NULL || head->begin_b->next == NULL)
		return ;
	while (head->stack_b->next->next)
		head->stack_b = head->stack_b->next;
	transfer = head->stack_b->next;
	head->stack_b->next = NULL;
	head->stack_b = head->begin_b;
	transfer->next = head->begin_b;
	head->begin_b = transfer;
	head->stack_b = head->begin_b;
	head->opr++;
	if (head->program == PUSH_SWAP && head->print == 1)
		ft_printf("rrb\n");
}

void		action_rrr(t_pushswap *head)
{
	head->print = 0;
	action_rra(head);
	head->opr--;
	action_rrb(head);
	head->print = 1;
	if (head->program == PUSH_SWAP)
		ft_printf("rrr\n");
}
