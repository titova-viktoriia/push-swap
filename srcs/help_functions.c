
#include "push_swap.h"

#include "push_swap.h"

t_pushswap		*initialization(int program, int argc)
{
	t_pushswap		*head;

	if (!(head = (t_pushswap *)malloc(sizeof(t_pushswap))))
		return (NULL);
	head->begin_a = NULL;
	head->stack_a = NULL;
	head->stack_b = NULL;
	head->begin_b = NULL;
	head->actions = NULL;
	head->help_array = NULL;
	head->block = NULL;
	head->image = NULL;
	head->program = program;
	head->count_of_elements = argc - 1;
	head->steps = 0;
	head->opr = 0;
	head->print = 1;
	head->i_str = 0;
	head->play_pause = PLAY;
	head->t_flag = 0;
	return (head);
}

void			clean_up(t_pushswap *head)
{
	t_stack *help;

	if (head->begin_a != NULL)
	{
		while (head->begin_a)
		{
			help = head->begin_a->next;
			free(head->begin_a);
			head->begin_a = help;
		}
	}
	if (head->begin_b != NULL)
	{
		while (head->begin_b)
		{
			help = head->begin_b->next;
			free(head->begin_b);
			head->begin_b = help;
		}
	}
	if (head->actions != NULL)
		free(head->actions);
}

int				len_of_stack(t_stack *a)
{
	t_stack		*help;
	int			i;

	i = 0;
	help = a;
	while (help)
	{
		help = help->next;
		i++;
	}
	return (i);
}

void			print_stack(t_stack *stack)
{
	int			i;
	t_stack		*help;

	i = 0;
	help = stack;
	while (help)
	{
		ft_printf("%i = %i\n", i, help->cell);
		help = help->next;
		i++;
	}
}

void			common_print(t_pushswap *head)
{
	ft_printf("\nSTACK_A\t\t\t");
	ft_printf("STACK_B\n");
	while (head->stack_a || head->stack_b)
	{
		if (head->stack_a)
		{
			ft_printf(" %-20d", head->stack_a->cell);
			head->stack_a = head->stack_a->next;
		}
		if (head->stack_b)
		{
			ft_printf("%d\n", head->stack_b->cell);
			head->stack_b = head->stack_b->next;
		}
		else
			ft_printf("\n");
	}
	head->stack_a = head->begin_a;
	head->stack_b = head->begin_b;
}
