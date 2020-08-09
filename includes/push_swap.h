
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf.h"
# include "mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define CHECKER 1
# define PUSH_SWAP 2
# define WINDOW_X 1300
# define WINDOW_Y 1300
# define BUTSIZE 30
# define BUFFER 10
# define PLAY 1
# define PAUSE 2
# define SPACE_BUTTON 49
# define ESC_EXIT 53

typedef struct		s_block
{
	int				start;
	int				end;
	int				count;
	struct s_block	*next;
}					t_block;

typedef struct		s_stack
{
	int				cell;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_pushswap
{
	t_block		*block;
	void		*mlx;
	void		*win;
	void		*image;
	int			*data_img;
	int			bpp;
	int			size_line;
	int			endian;
	t_stack		*begin_a;
	t_stack		*begin_b;
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			*help_array;
	int			min;
	int			max;
	int			count_of_elements;
	int			steps;
	int			t_flag;
	int			first_a;
	int			second_a;
	int			last_a;
	int			program;
	int			play_pause;
	char		*actions;
	int			column_width;
	int			single_height;
	int			head_a;
	int			i_arr;
	int			count_b;
	int			opr;
	int			back_a;
	int			x;
	int			print;
	int			i_str;
}					t_pushswap;

t_pushswap			*initialization(int program, int argc);
void				clean_up(t_pushswap *head);
void				print_stack(t_stack *stack);
void				common_print(t_pushswap *head);
int					check_flags(t_pushswap *head, char **argv);
int					check_actions(t_pushswap *head);
int					check_argv(const char *str, char stop);
int					check_stack(t_stack *stack);
void				check_stack_print(t_stack *stack, t_stack *b);
int					check_stack_common(t_stack *stack, t_stack *b);
int					fill_stack(t_pushswap *head, char **argv);
int					fill_array(t_pushswap *head);
int					find_duplicates_min_and_max(t_pushswap *head);
void				action_ra(t_pushswap *head);
void				action_rb(t_pushswap *head);
void				action_rr(t_pushswap *head);
void				action_sa(t_pushswap *head);
void				action_sb(t_pushswap *head);
void				action_ss(t_pushswap *head);
void				action_pa(t_pushswap *head);
void				action_pb(t_pushswap *head);
void				action_rra(t_pushswap *head);
void				action_rrb(t_pushswap *head);
void				action_rrr(t_pushswap *head);
void				how_to_sort(t_pushswap *head);
void				sorting_algorithm(t_pushswap *head);
void				sort_array(int *arr, int start, int end);
void				vis_initialization(t_pushswap *head);
void				sorting_algorithm_three(t_pushswap *head);
int					len_of_stack(t_stack *a);
t_block				*new_block(void);
t_block				*add_new_block(t_block *block, t_block *new);
void				remove_one_block(t_pushswap *head);
void				fill_block(t_block *block, int start, int count);
void				get_block(t_pushswap *head, int start, int count);
void				from_stack_a_to_b_small(t_pushswap *head);
void				from_stack_a_to_b_big(t_pushswap *head);
void				from_the_top_a(t_pushswap *head, int count, int i_array);
void				from_stack_a_to_b(t_pushswap *head);
int					get_place_of_number(t_pushswap *head, int num);
void				case_from_head_b(t_pushswap *head, int count, int i);
void				case_from_end_b(t_pushswap *head, int count, int i);
void				from_end_of_a(t_pushswap *head);
void				from_b_to_a(t_pushswap *head);
void				image_creation(t_pushswap *head);
int					program_control(t_pushswap *head);
int					how_to_sort_mlxlh(t_pushswap *head);
void				how_to_sort(t_pushswap *head);
void				how_to_sort_1(t_pushswap *head);

#endif
