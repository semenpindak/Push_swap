/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:09:54 by calpha            #+#    #+#             */
/*   Updated: 2020/08/26 23:02:32 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_number(t_number *list_b)
{
	int min;
	int n;

	min = list_b->n;
	n = list_b->n;
	while(list_b)
	{
		list_b = list_b->next;
		if (list_b->n < min)
			min = list_b->n;
		if (n == list_b->n)
			break;
	}
	return (min);
}

static int	checking_stack_sorted(t_number *list_a, int min, int n)
{
	int current;

	while (list_a)
	{
		if (list_a->n == min)
			break;
		list_a = list_a->next;
	};
	n--;
	while (list_a)
	{
		current = list_a->n;
		list_a = list_a->next;
		if (current < list_a->n)
		{
			n--;
			if (n == 0)
				return (1);
		}
		else
			return (0);
	}
	return (-1);
}

static void	when_parameters_one_two(int ac)
{
	if (ac == 1)
	{
		printf("Enter more than one parameter\n");
		exit (0);
	}
	if (ac == 2)
		exit (0);
}

int			main(int ac, char *av[])
{
	t_number *list_a;
	t_number *list_b;
	int n;
	int min;

	list_b = NULL;
	if (ac == 1 || ac == 2)
		when_parameters_one_two(ac);
	// if (validation(ac, av) == 0)
	// {
	// 	ft_putstr("Error\n");
	// 	exit (0);
	// }
	list_a = create_stack_a(ac, av);
	n = count_list(list_a);
	min = find_min_number(list_a);
	if (checking_stack_sorted(list_a, min, n) == 1)
		exit (0);
	// if(ft_strcmp(av[1], "-v") == 0)
		// timsort(list_a, list_b);
	if (n <= 10)
		sorting_upten_num(list_a, list_b);
	else
		timsort(list_a, list_b);
	return (0);
}
