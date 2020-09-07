/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:09:00 by calpha            #+#    #+#             */
/*   Updated: 2020/09/07 01:53:13 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct		s_num
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
	struct s_num	*next;
	struct s_num	*prev;
}					t_num;

typedef struct		s_key
{
	int				key;
	int				i;
	int				print;
}					t_key;

char				**parser(int ac, char *av[], int *ret);
int					validation(int ac, char *av[]);
t_num				*create_stack_a(int ac, char *av[]);

void				debug_print(t_num *list_a, t_num *list_b, t_key *bonus);
void				debug_print_two(t_num **list_a, t_num **list_b, t_key *bonus);

void				show_me(t_num *list_a, t_num *list_b, t_key *bonus);
void				show_me_two(t_num **list_a, t_num **list_b, t_key *bonus);
void				show_me_three(t_num ***list_a, t_num ***list_b, t_key *bonus);

void				timsort(t_num *list_a, t_num *list_b, t_key *bonus);
void				insertsort_first(t_num **list_a, t_num **list_b, int d, t_key *bonus);
void				insertsort_regular(t_num **list_a, t_num **list_b, int d, t_key *bonus);
void				mergesort_first(t_num **list_a, t_num **list_b, t_key *bonus);
void				mergesort_regular(t_num **list_a, t_num **list_b, t_key *bonus);

void				sort_ten_num(t_num *list_a, t_num *list_b, t_key *bonus);
void				insertsort_finish(t_num **list_a, t_num **list_b, t_key *bonus);

void				centering_stack_first(t_num **list_a, t_num **list_b, t_key *bonus);
void				centering_stack_regular(t_num **list_a, t_num **list_b, t_key *bonus);
void				centering_stack_finish(t_num **list_a, t_num **list_b, t_key *bonus);

void				pb_when_stack_b_null(t_num **list_a, t_num **list_b, t_key *bonus);

void				find_min_steps_first(t_num **list_a, t_num **list_b);
void				find_min_steps_regular(t_num **list_a, t_num **list_b);

void				count_step_in_b_first(t_num **list_a, t_num **list_b);
void				count_step_in_b_regular(t_num **list_a, t_num **list_b);
void				count_step_in_a(t_num **list_a, t_num **list_b);

void				rotation_stack_a(t_num **list_a, t_num **list_b, t_key *bonus, int spin);
void				rotation_stack_b(t_num **list_a, t_num **list_b, t_key *bonus, int spin);
void				joint_rotation(t_num **list_a, t_num **list_b, t_key *bonus, int spin);

int					count_list(t_num *list_a);
int					count_list_two(t_num **list_a);
int					count_list_three(t_num ***list_a);

void				sa(t_num *list_a, t_key *bonus);
void				sb(t_num *list);
int					ss(t_num *list_a, t_num *list_b);

void				sa_two(t_num **list_a, t_key *bonus);
void				pa(t_num **list_a, t_num **list_b, t_key *bonus);
void				pb(t_num **list_a, t_num **list_b, t_key *bonus);
void				ra(t_num **list_a, t_key *bonus);
void				rb(t_num **list_b, t_key *bonus);
void				rr(t_num **list_a, t_num **list_b, t_key *bonus);
void				rra(t_num **list_a, t_key *bonus);
void				rrb(t_num **list_b, t_key *bonus);
void				rrr(t_num **list_a, t_num **list_b, t_key *bonus);

void				pa_three(t_num ***list_a, t_num ***list_b, t_key *bonus);
void				pb_three(t_num ***list_a, t_num ***list_b, t_key *bonus);
void				ra_three(t_num ***list_a, t_key *bonus);
void				rb_three(t_num ***list_b, t_key *bonus);
void				rr_three(t_num ***list_a, t_num ***list_b, t_key *bonus);
void				rra_three(t_num ***list_a, t_key *bonus);
void				rrb_three(t_num ***list_b, t_key *bonus);
void				rrr_three(t_num ***list_a, t_num ***list_b, t_key *bonus);
#endif
