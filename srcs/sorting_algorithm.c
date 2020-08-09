
#include "push_swap.h"

int			get_place_of_number(t_pushswap *head, int num)
{
	t_stack		*b;
	int			i;

	i = 1;
	b = head->stack_b;
	while (b->cell != num)
	{
		b = b->next;
		i++;
	}
	return (i);
}

void		get_first_second_last(t_pushswap *head)
{
	t_stack *help;

	help = head->stack_a;
	head->first_a = help->cell;
	head->second_a = help->next->cell;
	while (help->next)
		help = help->next;
	head->last_a = help->cell;
}

void		sorting_algorithm_three(t_pushswap *head)
{
	while (check_stack(head->stack_a) == 0)
	{
		get_first_second_last(head);
		if (head->first_a > head->last_a && head->second_a < head->last_a)
			action_ra(head);
		else if (head->first_a < head->second_a && head->first_a > head->last_a)
			action_rra(head);
		else
		{
			if (head->begin_b != NULL && head->begin_b->next != NULL
			&& head->begin_b->cell < head->begin_b->next->cell)
				action_ss(head);
			else
				action_sa(head);
		}
		head->steps++;
	}
}

void		sorting_algorithm(t_pushswap *head)
{
	if (head->count_of_elements == 1 || check_stack(head->stack_a) == 1)
		return ;
	else if (head->count_of_elements <= 3)
		sorting_algorithm_three(head);
	else
	{
		if (head->count_of_elements <= 10)
			from_stack_a_to_b_small(head);
		else if (head->count_of_elements < 200)
			from_stack_a_to_b(head);
		else
			from_stack_a_to_b_big(head);
		sorting_algorithm_three(head);
		from_b_to_a(head);
	}
}
