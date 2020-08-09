
#include "push_swap.h"

static void		help_if_1(t_pushswap *head)
{
	action_pa(head);
	action_ra(head);
	head->back_a++;
	head->count_b--;
}

void			case_from_head_b(t_pushswap *head, int count, int i)
{
	head->head_a = 0;
	while (i < count)
	{
		if (head->stack_b->cell == head->help_array[head->back_a]
			&& head->block->count > 4 && head->back_a != head->i_arr)
			help_if_1(head);
		else if (head->stack_b->cell == head->help_array[head->i_arr - 1])
		{
			action_pa(head);
			head->head_a++;
		}
		else
			action_rb(head);
		i++;
	}
	action_pa(head);
	if (head->head_a > 0)
	{
		head->i_arr--;
		head->count_b--;
		if (head->stack_a->cell > head->stack_a->next->cell)
			action_sa(head);
	}
}

void			case_from_end_b(t_pushswap *head, int count, int i)
{
	head->head_a = 0;
	while (i < count + 1)
	{
		action_rrb(head);
		if (head->stack_b->cell == head->help_array[head->i_arr - 1])
		{
			action_pa(head);
			head->head_a++;
		}
		else if (head->stack_b->cell == head->help_array[head->back_a]
		&& head->block->count > 4 && head->back_a != head->i_arr)
			help_if_1(head);
		i++;
	}
	action_pa(head);
	if (head->head_a > 0)
	{
		head->i_arr--;
		head->count_b--;
		if (head->stack_a->cell > head->stack_a->next->cell)
			action_sa(head);
	}
}

void			from_b_to_a(t_pushswap *head)
{
	int		num;
	int		place;

	head->count_b = head->count_of_elements - len_of_stack(head->stack_a);
	while (head->block != NULL)
	{
		head->back_a = head->block->start;
		head->i_arr = head->block->end;
		while (head->back_a <= head->i_arr)
		{
			num = head->help_array[head->i_arr];
			place = get_place_of_number(head, num);
			if (place <= head->count_b / 2 || head->count_b == 1)
				case_from_head_b(head, place, 1);
			else
				case_from_end_b(head, head->count_b - place, 0);
			head->i_arr--;
			head->count_b--;
		}
		from_end_of_a(head);
		remove_one_block(head);
	}
}
