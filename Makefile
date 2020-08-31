LIBFT		= libft/libft.a
PRINTF		= ft_printf/libftprintf.a

PUSH_SWAP	= push_swap
CHECKER		= checker

SRC_PS		= push_swap.c validation.c create_stack_a.c\
			  timsort.c insertion_sort_first.c merge_sort_first.c sorting_upten_num.c sorting_upten_num_kv.c\
			  centering_stack_first.c insertion_sort_regular.c centering_stack_regular.c\
			  centering_stack_regular_a.c centering_stack_a.c centering_stack_a_kv.c merge_sort_regular.c\
			  pb_when_stack_b_null.c\
			  sa.c sb.c ss.c pa.c pb.c ra.c rb.c rr.c rra.c rrb.c rrr.c\
			  pa_three.c pb_three.c ra_three.c rb_three.c rr_three.c rra_three.c rrb_three.c rrr_three.c\
			  ra_four.c rra_four.c\
			  show_me.c show_me_two.c show_me_three.c\
			  count_step_in_b.c count_step_in_b_for_struct.c count_step_in_b_for_struct_three.c\
			  count_step_in_b_for_struct_three_regular.c\
			  find_min_steps_from_a_to_b.c find_min_steps_from_a_to_b_three.c find_min_steps_from_a_to_b_three_regular.c\
			  count_list.c count_list_two.c count_list_three.c parser.c\
			  timsort_kv.c insertion_sort_first_kv.c insertion_sort_regular_kv.c merge_sort_first_kv.c merge_sort_regular_kv.c\
			  centering_stack_first_kv.c centering_stack_regular_kv.c centering_stack_regular_a_kv.c pb_when_stack_b_null_kv.c
SRC_CH		= checker.c parser.c validation.c create_stack_a.c count_list.c\
			  sa.c sb.c ss.c pa.c pb.c ra.c rb.c rr.c rra.c rrb.c rrr.c\
			  sa_checker.c pa_checker.c pb_checker.c ra_checker.c rb_checker.c rr_checker.c\
			  rra_checker.c rrb_checker.c rrr_checker.c

OBJ_PS		= $(SRC_PS:c=o)
OBJ_CH		= $(SRC_CH:c=o)

CFLAGS		= -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP): $(OBJ_PS) $(LIBFT) $(PRINTF)
	${CC} $(CFLAGS) ${OBJ_PS} -L libft/ -l ft -L ft_printf/ -l ftprintf -o ${PUSH_SWAP}


$(CHECKER): $(OBJ_CH) $(LIBFT) $(PRINTF)
	${CC} $(CFLAGS) ${OBJ_CH} -L libft/ -l ft -L ft_printf/ -l ftprintf -o ${CHECKER}

$(LIBFT):
	make -C libft/

$(PRINTF):
	make -C ft_printf/

%.o: %.c
	${CC} ${CFLAGS} -g -MD -c $<
include $(wildcard *.d)

clean:
	rm -f $(OBJ_PS) $(OBJ_CH) *.d .DS_Store && make clean -C libft/ && make clean -C ft_printf/

fclean: clean
	rm -f $(PUSH_SWAP) $(CHECKER) && make fclean -C libft/ && make fclean -C ft_printf/

re: fclean all
