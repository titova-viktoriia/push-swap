
#include "push_swap.h"

static int		check_duplicates(int number, t_stack *stack)
{
	t_stack *help;

	help = stack;
	while (help)
	{
		if (help->cell == number)
			return (-1);
		help = help->next;
	}
	return (1);
}

int				find_duplicates_min_and_max(t_pushswap *head)
{
	int i;

	head->min = head->stack_a->cell;
	head->max = head->stack_a->cell;
	while (head->stack_a->next)
	{
		i = head->stack_a->cell;
		head->stack_a = head->stack_a->next;
		if (head->stack_a->cell < head->min)
			head->min = head->stack_a->cell;
		if (head->stack_a->cell > head->max)
			head->max = head->stack_a->cell;
		if (check_duplicates(i, head->stack_a) == -1)
			return (0);
	}
	head->stack_a = head->begin_a;
	return (1);
}
