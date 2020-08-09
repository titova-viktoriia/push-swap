
#include "push_swap.h"

int				main(int argc, char **argv)
{
	t_pushswap		*head;

	if (argc > 1)
	{
		if (!(head = initialization(CHECKER, argc)))
			return (0);
		if (check_flags(head, argv) == 0 || fill_stack(head, argv) == 0
			|| check_actions(head) == 0)
		{
			clean_up(head);
			free(head);
			ft_printf("Error\n");
			return (0);
		}
		vis_initialization(head);
	}
	return (0);
}
