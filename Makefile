NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g
INCLUDES    = -Ilibft -Isrc
RM          = rm -f
RM_DIR      = rm -rf

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

# --- Source Files (with full paths) ---
PS_SRCS = \
    src/main.c \
    src/allowed_ops/swap_ops.c \
    src/allowed_ops/push_ops.c \
    src/allowed_ops/rotate_ops.c \
    src/allowed_ops/rev_rotate_ops.c \
    src/sorting_algorithm/turk_sort.c \
    src/sorting_algorithm/small_cases.c \
    src/sorting_algorithm/final_rotation.c \
    src/sorting_algorithm/init_nodes.c \
    src/sorting_algorithm/find_targets.c \
    src/sorting_algorithm/calc_costs.c \
    src/sorting_algorithm/execute_moves.c \
    src/sorting_algorithm/a2b_rotation_moves.c \
	src/stack/stack_nav.c \
	src/stack/stack_order.c \
	src/stack/stack_ops.c \
    src/parsing/input_to_stack.c \
    src/parsing/parse_validate.c

# --- Objects ---
OBJ_DIR      = objs
PS_OBJS      = $(patsubst %.c,$(OBJ_DIR)/%.o,$(PS_SRCS))

# --- Rules ---
.PHONY: all clean fclean re

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(PS_OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(PS_OBJS) $(LIBFT) -o $(NAME)
	@echo "push_swap compiled!"

# Rule to compile .c files into .o files, creating subdirs in objs
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(RM_DIR) $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@$(RM) $(NAME) $(BONUS_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all