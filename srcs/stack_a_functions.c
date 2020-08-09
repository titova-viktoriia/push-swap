
#include "push_swap.h"

void		from_the_top_a(t_pushswap *head, int count, int i_array)
{
	int i;
	int compared;
	int compared_2;

	i = 0;
	compared = head->help_array[i_array + count - 1];
	compared_2 = head->help_array[i_array + count / 2 - 1];
	while (i < count)
	{
		if (head->stack_a->cell > compared)
			action_ra(head);
		else
		{
			i++;
			action_pb(head);
			if (head->stack_b->cell <= compared_2 && count > 4)
			{
				if (head->stack_a->cell > compared)
					action_rr(head);
				else
					action_rb(head);
			}
		}
	}
}

void		from_stack_a_to_b_small(t_pushswap *head)
{
	int i;
	int count_2;

	count_2 = head->count_of_elements - 3;
	i = 0;
	get_block(head, 0, count_2);
	while (i < count_2)
	{
		if (head->stack_a->cell >=
		head->help_array[head->count_of_elements - 3])
			action_ra(head);
		else
		{
			action_pb(head);
			i++;
		}
	}
}

void		from_stack_a_to_b_big(t_pushswap *head)
{
	int i;
	int count;
	int count_2;
	int del;

	del = (head->count_of_elements - 3) / 100;
	count = head->count_of_elements;
	count_2 = 100;
	i = 0;
	while (count > 3)
	{
		if (count_2 > 4)
		{
			get_block(head, i, count_2 / 2);
			get_block(head, i + count_2 / 2, nummod(count_2));
		}
		else
			get_block(head, i, count_2);
		from_the_top_a(head, count_2, i);
		i = i + count_2;
		del--;
		count = count - count_2;
		if (del < 1)
			count_2 = nummod(count);
	}
}

void		from_stack_a_to_b(t_pushswap *head)
{
	int i;
	int count;
	int count_2;

	count = head->count_of_elements;
	count_2 = nummod(count);
	i = 0;
	while (count > 3)
	{
		if (count_2 > 4)
		{
			get_block(head, i, count_2 / 2);
			get_block(head, i + count_2 / 2, nummod(count_2));
		}
		else
			get_block(head, i, count_2);
		from_the_top_a(head, count_2, i);
		i = i + count_2;
		count = count - count_2;
		count_2 = nummod(count);
	}
}

void		from_end_of_a(t_pushswap *head)
{
	int i;

	i = 0;
	while (i < head->back_a - head->block->start)
	{
		action_rra(head);
		i++;
	}
}
