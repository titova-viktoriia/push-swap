
#include "push_swap.h"

void		action_ra(t_pushswap *head)
{
	t_stack		*transfer;

	if (head->begin_a == NULL || head->begin_a->next == NULL)
		return ;
	head->begin_a = head->stack_a->next;
	transfer = head->stack_a;
	while (head->stack_a->next)
		head->stack_a = head->stack_a->next;
	transfer->next = NULL;
	head->stack_a->next = transfer;
	head->stack_a = head->begin_a;
	head->opr++;
	if (head->program == PUSH_SWAP && head->print == 1)
		ft_printf("ra\n");
}

void		action_rb(t_pushswap *head)
{
	t_stack		*transfer;

	if (head->begin_b == NULL || head->begin_b->next == NULL)
		return ;
	head->begin_b = head->stack_b->next;
	transfer = head->stack_b;
	while (head->stack_b->next)
		head->stack_b = head->stack_b->next;
	transfer->next = NULL;
	head->stack_b->next = transfer;
	head->stack_b = head->begin_b;
	head->opr++;
	if (head->program == PUSH_SWAP && head->print == 1)
		ft_printf("rb\n");
}

void		action_rr(t_pushswap *head)
{
	head->print = 0;
	action_rb(head);
	head->opr--;
	action_ra(head);
	head->print = 1;
	if (head->program == PUSH_SWAP)
		ft_printf("rr\n");
}
