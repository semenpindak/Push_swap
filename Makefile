LIBFT		= libft/libft.a
PRINTF		= ft_printf/libftprintf.a

PUSH_SWAP	= push_swap
CHECKER		= checker

SRC_PS		= push_swap.c parser.c validation.c create_stack_a.c\
			  debug_print.c debug_print_two.c show_me.c show_me_two.c show_me_three.c\
			  timsort.c insertsort_first.c mergesort_first.c insertsort_regular.c mergesort_regular.c\
			  sort_ten_num.c insertion_sort_finish.c\
			  centering_stack_first.c centering_stack_regular.c centering_stack_finish.c\
			  pb_when_stack_b_null.c\
			  find_min_steps_first.c find_min_steps_regular.c\
			  count_step_in_a.c count_step_in_b_first.c count_step_in_b_regular.c\
			  count_list.c count_list_two.c count_list_three.c\
			  sa.c sb.c ss.c sa_two.c pa.c pb.c ra.c rb.c rr.c rra.c rrb.c rrr.c\
			  pa_three.c pb_three.c ra_three.c rb_three.c rr_three.c rra_three.c rrb_three.c rrr_three.c\
			  rotation_stack_a.c rotation_stack_b.c joint_rotation.c\

SRC_CH		= checker.c parser.c validation.c create_stack_a.c count_list.c count_list_two.c\
			  sa_two.c pa_three.c pb_three.c ra_three.c rb_three.c rr_three.c rra_three.c rrb_three.c rrr_three.c\

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
