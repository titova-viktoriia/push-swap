
#include "push_swap.h"

static int			key_press(int button, t_pushswap *head)
{
	if (button == ESC_EXIT)
	{
		mlx_destroy_image(head->mlx, head->image);
		mlx_destroy_window(head->mlx, head->win);
		check_stack_print(head->stack_a, head->stack_b);
		clean_up(head);
		free(head);
		exit(0);
	}
	if (button == SPACE_BUTTON)
	{
		if (head->play_pause == PLAY)
			head->play_pause = PAUSE;
		else if (head->play_pause == PAUSE)
			head->play_pause = PLAY;
	}
	return (1);
}

int					program_control(t_pushswap *head)
{
	mlx_hook(head->win, 2, 0, key_press, head);
	return (1);
}
