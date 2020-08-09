
#include "push_swap.h"

static t_stack	*new_element(long long number)
{
	t_stack		*new;

	if (number < -2147483648 || number > 2147483647)
		return (NULL);
	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	new->cell = (int)number;
	new->next = NULL;
	return (new);
}

static int		fill_from_str(t_pushswap *head, char **argv, int i, int i_2)
{
	t_stack		*help;

	if (argv[i][0] == '\0' || (argv[i][0] == ' ' && argv[i][1] == '\0'))
		return (0);
	while (argv[i][i_2] != '\0')
	{
		if (check_argv(argv[i] + i_2, ' ') == -1 ||
			!(help = new_element(ft_atoi_long_long(argv[i] + i_2))))
			return (0);
		head->stack_a->next = help;
		head->stack_a = head->stack_a->next;
		i_2 = i_2 + (int)ft_strlen_sym(argv[i] + i_2, ' ');
		head->count_of_elements++;
		if (argv[i][i_2] == ' ')
			i_2++;
	}
	return (1);
}

static int		fill_from_argv(t_pushswap *head, char **argv, int count)
{
	int			i;
	int			i_2;

	i = 1;
	i_2 = 0;
	if (check_argv(argv[i] + i_2, ' ') == -1 ||
	!(head->stack_a = new_element(ft_atoi_long_long(argv[i] + i_2))))
		return (0);
	i_2 = i_2 + (int)ft_strlen_sym(argv[i], ' ');
	if (argv[i][i_2] == ' ')
		i_2++;
	head->begin_a = head->stack_a;
	head->count_of_elements = 1;
	while (i <= count)
	{
		if (fill_from_str(head, argv, i, i_2) == 0)
			return (0);
		i_2 = 0;
		i++;
	}
	head->stack_a = head->begin_a;
	return (1);
}

int				fill_stack(t_pushswap *head, char **argv)
{
	if (fill_from_argv(head, argv, head->count_of_elements) == 0)
		return (0);
	if (find_duplicates_min_and_max(head) == 0)
		return (0);
	if (head->program == PUSH_SWAP)
	{
		if (fill_array(head) == 0)
			return (0);
	}
	return (1);
}
