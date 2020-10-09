LIBFT		= Libft/libft.a

PUSH_SWAP	= push_swap
CHECKER		= checker

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g

INC_DIR := includes
SRC_DIR := sources
OBJ_DIR := objects

SRC_PS		= push_swap.c parser.c validation.c create_stack_a.c\
			  debug_print.c debug_print_two.c show_me.c show_me_two.c show_me_three.c\
			  timsort.c insertsort_first.c mergesort_first.c insertsort_regular.c mergesort_regular.c\
			  sort_ten_num.c insertion_sort_finish.c\
			  centering_stack_first.c centering_stack_regular.c centering_stack_finish.c\
			  pb_when_stack_b_null.c\
			  find_min_steps_first.c find_min_steps_regular.c\
			  count_step_in_a.c count_step_in_b_first.c count_step_in_b_regular.c\
			  count_list.c count_list_two.c count_list_three.c\
			  sa.c sa_two.c pa.c pb.c ra.c rb.c rr.c rra.c rrb.c rrr.c\
			  rotation_stack_a.c rotation_stack_b.c rotation_both_stacks.c free_array.c

SRC_CH		= checker.c parser.c validation.c create_stack_a.c count_list.c count_list_two.c\
			  sa_two.c pa.c pb.c ra.c rb.c rr.c rra.c rrb.c rrr.c free_array.c

OBJ_PS		= $(addprefix $(OBJ_DIR)/,$(SRC_PS:%.c=%.o))
OBJ_CH		= $(addprefix $(OBJ_DIR)/,$(SRC_CH:%.c=%.o))

all:	$(OBJ_DIR) $(PUSH_SWAP) $(CHECKER)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(PUSH_SWAP): $(OBJ_PS) $(LIBFT)
	${CC} $(CFLAGS) ${OBJ_PS} $(SRC_PUSHSWAP) -L Libft/ -l ft -o ${PUSH_SWAP}

$(CHECKER): $(OBJ_CH) $(LIBFT)
	${CC} $(CFLAGS) ${OBJ_CH} $(SRC_CHECKER) -L Libft/ -l ft -o ${CHECKER}

$(LIBFT):
	make -C Libft/

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	${CC} ${CFLAGS} -I ./$(INC_DIR) -MD -c $< -o $@
include $(wildcard *.d)

clean:
	rm -rf $(OBJ_DIR) && make clean -C Libft/

fclean: clean
	rm -f $(PUSH_SWAP) $(CHECKER) && make fclean -C Libft

re: fclean all

.PHONY: all clean fclean re
