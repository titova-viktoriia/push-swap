
#include "push_swap.h"

void		action_sa(t_pushswap *head)
{
	t_stack		*transfer;
	t_stack		*transfer_next;

	if (head->begin_a == NULL || head->begin_a->next == NULL)
		return ;
	head->begin_a = head->stack_a->next;
	transfer = head->stack_a;
	head->stack_a = head->stack_a->next;
	transfer_next = head->stack_a->next;
	head->stack_a->next = transfer;
	transfer->next = transfer_next;
	head->stack_a = head->begin_a;
	head->opr++;
	if (head->program == PUSH_SWAP && head->print == 1)
		ft_printf("sa\n");
}

void		action_sb(t_pushswap *head)
{
	t_stack		*transfer;
	t_stack		*transfer_next;

	if (head->begin_b == NULL || head->begin_b->next == NULL)
		return ;
	head->begin_b = head->stack_b->next;
	transfer = head->stack_b;
	head->stack_b = head->stack_b->next;
	transfer_next = head->stack_b->next;
	head->stack_b->next = transfer;
	transfer->next = transfer_next;
	head->stack_b = head->begin_b;
	head->opr++;
	if (head->program == PUSH_SWAP && head->print == 1)
		ft_printf("sb\n");
}

void		action_ss(t_pushswap *head)
{
	head->print = 0;
	action_sa(head);
	head->opr--;
	action_sb(head);
	head->print = 1;
	if (head->program == PUSH_SWAP)
		ft_printf("ss\n");
}
