PROGRAM = push_swap
CFLAGS:= -Wall -Wextra -Werror
SRCS =	main.c\
		validation.c\
		sorting.c
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
