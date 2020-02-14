PROGRAM = checker
CFLAGS:= -Wall -Wextra -Werror
SRCS = main.c
OBJ = $(SRCS:c=o)


.PHONY: all clean fclean re

all: $(PROGRAM)
$(PROGRAM): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -g -MD -c $<
include $(wildcard *.d)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(PROGRAM)

re: fclean all
