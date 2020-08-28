LIBFT		= libft/libft.a

PROGRAM_PS	= push_swap
# PROGRAM_CH	= checker

SRC_PS		= main.c validation.c create_stack_a.c\
			  timsort.c insertion_sort_first.c merge_sort_first.c sorting_upten_num.c\
			  centering_stack_first.c insertion_sort_regular.c centering_stack_regular.c\
			  centering_stack_regular_a.c centering_stack_a.c merge_sort_regular.c\
			  pb_when_stack_b_null.c\
			  sa.c sb.c ss.c pa.c pb.c ra.c rb.c rr.c rra.c rrb.c rrr.c\
			  pa_three.c pb_three.c ra_three.c rb_three.c rr_three.c rra_three.c rrb_three.c rrr_three.c\
			  ra_four.c rra_four.c\
			  show_me.c show_me_two.c show_me_three.c\
			  count_step_in_b.c count_step_in_b_for_struct.c count_step_in_b_for_struct_three.c\
			  count_step_in_b_for_struct_three_regular.c\
			  find_min_steps_from_a_to_b.c find_min_steps_from_a_to_b_three.c find_min_steps_from_a_to_b_three_regular.c\
			  count_list.c count_list_two.c count_list_three.c
OBJ_PS		= $(SRC_PS:c=o)

# SRC_CH		=
# OBJ_CH		= $(SRC_CH:c=o)

CFLAGS		= -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(PROGRAM_PS)

$(PROGRAM_PS): $(OBJ_PS) $(LIBFT)
	${CC} $(CFLAGS) ${OBJ_PS} -o ${PROGRAM_PS} -L libft/ -l ft

%.o: %.c
	${CC} ${CFLAGS} -g -MD -c $<

$(LIBFT):
	make -C libft/

include $(wildcard *.d)

clean:
	rm -f $(OBJ_PS) *.d .DS_Store && make clean -C libft/

fclean: clean
	rm -f $(PROGRAM_PS) && make fclean -C libft/

re: fclean all
