
#include "push_swap.h"

static void		background(int *str, int x, int y)
{
	int i;

	i = 0;
	while (i <= x * y)
	{
		str[i] = 0;
		i++;
	}
}

static void		draw_stack_a(t_pushswap *head, int y, int i)
{
	while (head->stack_a)
	{
		while (head->x < head->column_width * i)
		{
			while (y < head->single_height * ft_abs(head->stack_a->cell))
			{
				if (head->stack_a->cell < 0)
					head->data_img[WINDOW_X *
					(WINDOW_Y - y - 1) + head->x] = 255;
				else
					head->data_img[WINDOW_X *
					(WINDOW_Y - y - 1) + head->x] = 6724044;
				y++;
			}
			y = 0;
			head->x++;
		}
		i++;
		head->stack_a = head->stack_a->next;
	}
	head->stack_a = head->begin_a;
}

static void		draw_separator(t_pushswap *head)
{
	int y;
	int i;

	i = 0;
	y = 0;
	while (i < 10)
	{
		while (y < WINDOW_Y - BUTSIZE)
		{
			y++;
			head->data_img[WINDOW_X * (WINDOW_Y - y - 1) + head->x] = 16777200;
		}
		y = 0;
		i++;
		head->x++;
	}
}

static void		draw_stack_b(t_pushswap *head, int x, int y, int i)
{
	while (head->stack_b)
	{
		while (x < head->column_width * i)
		{
			while (y < head->single_height * ft_abs(head->stack_b->cell))
			{
				if (head->stack_b->cell < 0)
					head->data_img[WINDOW_X *
					(WINDOW_Y - y - 1) + head->x] = 255;
				else
					head->data_img[WINDOW_X *
					(WINDOW_Y - y - 1) + head->x] = 6724044;
				y++;
			}
			y = 0;
			head->x++;
			x++;
		}
		i++;
		head->stack_b = head->stack_b->next;
	}
	head->stack_b = head->begin_b;
}

void			image_creation(t_pushswap *head)
{
	head->x = 0;
	background(head->data_img, WINDOW_X, WINDOW_Y);
	draw_stack_a(head, 0, 1);
	draw_separator(head);
	draw_stack_b(head, 0, 0, 1);
	mlx_put_image_to_window(head->mlx, head->win, head->image, 0, 0);
}
