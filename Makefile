PROGRAM = push_swap
CFLAGS:= -Wall -Wextra -Werror
SRCS =	main.c\
		validation.c\
		create_stack_a.c\
		timsort.c\
		insertion_sort_first.c\
		merge_sort_first.c\
		insertion_sort_regular.c\
		sa.c sb.c ss.c\
		pa.c pb.c\
		ra.c rb.c rr.c\
		rra.c rrb.c rrr.c\
		pa_three.c pb_three.c\
		ra_three.c rb_three.c rr_three.c\
		rra_three.c rrb_three.c rrr_three.c\
		show_me.c\
		show_me_two.c\
		show_me_b.c\
		find_median_number.c\
		count_step_in_b.c\
		count_step_in_b_for_struct.c\
		count_step_in_b_for_struct_three.c\
		count_step_in_b_for_struct_three_regular.c\
		find_min_steps_from_a_to_b.c\
		find_min_steps_from_a_to_b_three.c\
		find_min_steps_from_a_to_b_three_regular.c
OBJ = $(SRCS:c=o)

.PHONY: all clean fclean re

all: $(PROGRAM)
$(PROGRAM): $(OBJ)
	make -C libft/
	${CC} $(CFLAGS) ${OBJ} -o $@ -L libft/ -lft

%.o: %.c
	${CC} ${CFLAGS} -g -MD -c $<
include $(wildcard *.d)

clean:
	rm -f $(OBJ) *.d .DS_Store && make clean -C libft/

fclean: clean
	rm -f $(PROGRAM) && make fclean -C libft/

re: fclean all
