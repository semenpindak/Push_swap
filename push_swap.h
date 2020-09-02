/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:09:00 by calpha            #+#    #+#             */
/*   Updated: 2020/09/02 13:19:57 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct		s_number
{
	int				n;
	int				la;
	int				ra;
	int				step_a;
	int				logic_a;
	int				lb;
	int				rb;
	int				step_b;
	int				logic_b;
	int				sum_steps;
	int				status;
	struct s_number	*next;
	struct s_number	*prev;
}					t_number;

int					validation(int ac, char *av[]);
t_number			*create_stack_a(int ac, char *av[]);

void				timsort(t_number *list_a, t_number *list_b);
void				insertion_sort_first(t_number **list_a, t_number **list_b, int quantity);
void				insertion_sort_regular(t_number **list_a, t_number **list_b, int quantity);
void				merge_sort_first(t_number **list_a, t_number **list_b);
void				merge_sort_regular(t_number **list_a, t_number **list_b);

void				sorting_upten_num(t_number *list_a, t_number *list_b);

void				centering_stack_first(t_number **list_b);
void				centering_stack_regular(t_number **list_a, t_number **list_b);
void				centering_stack_regular_a(t_number **list_a);
void				centering_stack_a(t_number **list_a);

void				pb_when_stack_b_null(t_number ***list_a);

int					sa(t_number *list);
int					sb(t_number *list);
int					ss(t_number *list_a, t_number *list_b);

void				pa(t_number **list_a, t_number **list_b);
void				pb(t_number **list_a, t_number **list_b);
void				ra(t_number **list_a);
void				rb(t_number **list_b);
void				rr(t_number **list_a, t_number **list_b);
void				rra(t_number **list_a);
void				rrb(t_number **list_b);
void				rrr(t_number **list_a, t_number **list_b);

void				pa_three(t_number ***list_a, t_number ***list_b);
void				pb_three(t_number ***list_a, t_number ***list_b);
void				ra_three(t_number ***list_a);
void				rb_three(t_number ***list_b);
void				rr_three(t_number ***list_a, t_number ***list_b);
void				rra_three(t_number ***list_a);
void				rrb_three(t_number ***list_b);
void				rrr_three(t_number ***list_a, t_number ***list_b);

void				ra_four(t_number ****list_a);
void				rra_four(t_number ****list_a);

void				show_me(t_number *list_a, t_number *list_b);
void				show_me_two(t_number **list_a, t_number **list_b);
void				show_me_three(t_number ***list_a, t_number ***list_b);

int					count_step_in_b(t_number *list_a, t_number *list_b, int *logic);
void				count_step_in_a(t_number **list_a, t_number **list_b);
void				count_step_in_b_for_struct(t_number *list_a, t_number *list_b);
void				count_step_in_b_for_struct_three(t_number **list_a, t_number **list_b);
void				count_step_in_b_for_struct_three_regular(t_number **list_a, t_number **list_b);

void				find_min_steps_from_a_to_b(t_number *list_a, t_number *list_b);
void				find_min_steps_from_a_to_b_three(t_number **list_a, t_number **list_b);
void				find_min_steps_from_a_to_b_three_regular(t_number **list_a, t_number **list_b);

int					count_list(t_number *list_a);
int					count_list_two(t_number **list_a);
int					count_list_three(t_number ***list_a);

char				**parser(int ac, char *av[], int *ret);

void				timsort_kv(t_number *list_a, t_number *list_b);
int					insertion_sort_first_kv(t_number **list_a, t_number **list_b, int quantity);
int					insertion_sort_regular_kv(t_number **list_a, t_number **list_b, int quantity, int i);
int					merge_sort_first_kv(t_number **list_a, t_number **list_b, int i);
int					merge_sort_regular_kv(t_number **list_a, t_number **list_b, int i);
int					centering_stack_first_kv(t_number **list_a, t_number **list_b, int i);
int					centering_stack_regular_kv(t_number **list_a, t_number **list_b, int i);
int					centering_stack_regular_a_kv(t_number **list_a, t_number **list_b, int i);
int					pb_when_stack_b_null_kv(t_number ***list_a, t_number ***list_b, int i);

void				sorting_upten_num_kv(t_number *list_a, t_number *list_b);
int					centering_stack_a_kv(t_number **list_a, t_number **list_b, int i);
void				insertion_sort_finish(t_number **list_a, t_number **list_b);

int					sa_checker(t_number *list);
void				pa_checker(t_number **list_a, t_number **list_b);
void				pb_checker(t_number **list_a, t_number **list_b);
void				ra_checker(t_number **list_a);
void				rb_checker(t_number **list_b);
void				rr_checker(t_number **list_a, t_number **list_b);
void				rra_checker(t_number **list_a);
void				rrb_checker(t_number **list_b);
void				rrr_checker(t_number **list_a, t_number **list_b);
#endif
