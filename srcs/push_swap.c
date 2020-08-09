
#include "push_swap.h"

int				main(int argc, char **argv)
{
	t_pushswap		*head;

	if (argc > 1)
	{
		if (!(head = initialization(PUSH_SWAP, argc)))
			return (0);
		if (fill_stack(head, argv) == 0)
		{
			clean_up(head);
			free(head);
			ft_printf("Error\n");
			return (0);
		}
		sort_array(head->help_array, 0,
				head->count_of_elements - 1);
		sorting_algorithm(head);
		clean_up(head);
		free(head->help_array);
		free(head);
	}
	return (0);
}
