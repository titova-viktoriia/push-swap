
#include "push_swap.h"

static int			required_values(t_pushswap *head)
{
	int stack_length;

	stack_length = WINDOW_Y - 1;
	head->single_height = 0;
	head->column_width = (WINDOW_X - 10) / head->count_of_elements;
	if (head->max != 0)
		head->single_height = stack_length / ft_abs(head->max);
	if (head->min != 0 && stack_length / abs(head->min) < head->single_height)
		head->single_height = stack_length / abs(head->min);
	if (head->single_height == 0 || head->count_of_elements > WINDOW_X - 10)
		return (0);
	return (1);
}

void				vis_initialization(t_pushswap *head)
{
	if (head->count_of_elements == 1)
	{
		ft_printf("Just one number\n");
		return ;
	}
	if (required_values(head) == 0)
	{
		ft_printf("The values are too large or there are too ");
		ft_printf("many elements to display them correctly.\n");
		ft_printf("You can use '-t' flag for text visualization.\n");
		return ;
	}
	head->mlx = mlx_init();
	head->win = mlx_new_window(head->mlx, WINDOW_X, WINDOW_Y, "PUSH SWAP");
	head->image = mlx_new_image(head->mlx, WINDOW_X, WINDOW_Y);
	head->data_img = (int *)mlx_get_data_addr(head->image, &head->bpp,
			&head->size_line, &head->endian);
	head->play_pause = PAUSE;
	image_creation(head);
	program_control(head);
	mlx_loop_hook(head->mlx, &how_to_sort_mlxlh, head);
	mlx_loop(head->mlx);
}

int					how_to_sort_mlxlh(t_pushswap *head)
{
	if (head->actions != NULL && head->actions[head->i_str] != '\0'
		&& head->play_pause == PLAY)
	{
		how_to_sort_1(head);
		image_creation(head);
		while (head->actions[head->i_str] >= 'a'
			&& head->actions[head->i_str] <= 'z')
			head->i_str++;
		if (head->actions[head->i_str] != '\0')
			head->i_str++;
	}
	return (1);
}
