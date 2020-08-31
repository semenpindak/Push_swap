NAME	= libftprintf.a
HEADER	= ft_printf.h
CFLAGS	= -Wall -Wextra -Werror

SRCS 	=	ft_analazer_flags.c ft_init_procent.c ft_atoi_pres.c\
 			ft_init_spec.c ft_lltoa_base.c ft_print_d_i.c ft_printf.c\
 			ft_printf_o_u.c ft_write.c ft_printf_c.c ft_printf_s.c ft_printf_percent.c\
 			ft_printf_p.c ft_d_i.c ft_o_u.c ft_x_x.c ft_x_x_x.c double_number.c\
 			f_with_zero.c ft_itoa_c.c ft_itoa_frac.c ft_printf_f.c razrad.c\
 			ft_print_f_one.c ft_printf_x_x.c rounding.c flag_null.c\

OBJS = $(SRCS:c=o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	cp ../libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	${CC} ${CFLAGS} -g -MD -c $<
include $(wildcard *.d)

clean:
	rm -rf $(OBJS) *.d .DS_Store

fclean: clean
	rm -rf $(NAME)

re: fclean all
