PUSH_SWAP = push_swap
CHECKER = checker
VIS = visual

#sources and objects
COMMON_SRC =        actions_pa_pb.c \
                    actions_ra_rb_rr.c \
                    actions_rra_rrb_rrr.c \
                    actions_sa_sb_ss.c \
                    fill_stack.c \
                    find_duplicates_min_and_max.c \
                    validation_check.c \
                    functions_for_help_array.c \
                    help_functions.c \
                    checker_functions.c \
                    apply_actions.c

PUSH_SWAP_SRC =     push_swap.c \
                    functions_for_blocks.c \
                    sorting_algorithm.c \
                    stack_a_functions.c \
                    stack_b_functions.c

CHECKER_SRC =       checker_main.c \

VIS_SRC =           visualization_main.c \
					visualization.c \
                    functions_for_image.c \
                    program_control.c

PUSH_SWAP_SRC_PATH = = $(addprefix $(SRCDIR), $(PUSH_SWAP_SRC))
CHECKER_SRC_PATH = $(addprefix $(SRCDIR), $(CHECKER_SRC))
COMMON_SRC_PATH = $(addprefix $(SRCDIR), $(COMMON_SRC))
VIS_SRC_PATH = $(addprefix $(SRCDIR), $(VIS_SRC))

PUSH_SWAP_OBJ = $(addprefix $(OBJDIR), $(PUSH_SWAP_SRC:%.c=%.o))
CHECKER_OBJ = $(addprefix $(OBJDIR), $(CHECKER_SRC:%.c=%.o))
COMMON_OBJ = $(addprefix $(OBJDIR), $(COMMON_SRC:%.c=%.o))
VIS_OBJ = $(addprefix $(OBJDIR), $(VIS_SRC:%.c=%.o))

#directories
SRCDIR	= ./srcs/
INCDIR	= ./includes/
OBJDIR  = ./obj/

#includes
INC = -I ./includes

#flags
FLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

#library
FT		= ./libftprintf/
FT_LIB	= $(addprefix $(FT),libftprintf.a)
FT_INC	= -I ./libftprintf/includes -I ./libftprintf/srcs/libft/includes/
FT_LNK	= ./libftprintf/libftprintf.a

all: obj $(FT_LIB) $(PUSH_SWAP) $(CHECKER) $(VIS)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	gcc $(FLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(PUSH_SWAP): $(PUSH_SWAP_OBJ) $(COMMON_OBJ)
	gcc $(PUSH_SWAP_OBJ) $(COMMON_OBJ) $(FT_LNK) -o $(PUSH_SWAP)
$(CHECKER): $(CHECKER_OBJ) $(COMMON_OBJ)
	gcc $(CHECKER_OBJ) $(COMMON_OBJ) $(FT_LNK) -o $(CHECKER)

$(VIS):$(VIS_OBJ) $(COMMON_OBJ)
	gcc $(VIS_OBJ) $(COMMON_OBJ) $(MLX_FLAGS) $(FT_LNK) -o $(VIS)

$(FT_LIB):
	make -C $(FT)

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean

fclean: clean
	rm -rf $(PUSH_SWAP) $(CHECKER) $(VIS)
	make -C $(FT) fclean

re: fclean all
