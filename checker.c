/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 12:07:42 by oem               #+#    #+#             */
/*   Updated: 2020/09/02 23:49:47 by calpha           ###   ########.fr       */
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
		if (list_b->next != NULL)
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

	current = list_a->n;
	while (list_a)
	{
		if (list_a->n == min)
			break;
		if (list_a->next != NULL)
			list_a = list_a->next;
	};
	if (current != list_a->n)
		return (0);
	n--;
	while (list_a)
	{
		current = list_a->n;
		if (list_a->next != NULL)
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

static int check_space(char av[])
{
	int i;

	i = 0;
	while (av[i] != '\0')
	{
		if (av[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

static void	when_one_parameter(int ac, char *av[])
{
	if (ac == 1 || (ac == 2 && ft_strcmp(av[1], "\0") == 0))
	{
		printf("Enter more than one parameter\n");
		exit (0);
	}
	if (ac == 2 && check_space(av[1]) == 0)
	{
		printf("Enter more than one parameter\n");
		exit (0);
	}
}

int	main(int ac, char *av[])
{
	t_number *list_a;
	t_number *list_b;
	int n;
	int min;
	int ret;
	char *buff;

	list_b = NULL;
	if (ac == 1 || ac == 2)
		when_one_parameter(ac, av);

	av = parser(ac, av, &ac);

	if (validation(ac, av) == 0)
	{
		ft_putstr("Error\n");
		exit (0);
	}
	if (ac == 1)
		exit (0);

	list_a = create_stack_a(ac, av);

	n = count_list(list_a);

	min = find_min_number(list_a);

	if (checking_stack_sorted(list_a, min, n) == 1)
		exit (0);

	if (ac == 0 || ac == 1)
		return (0);
	if (ac > 1)
	{
		while ((ret = get_next_line(0, &buff)) > 0)
		{
			if (ft_strcmp(buff, "sa") == 0)
				sa_checker(list_a);
			if (ft_strcmp(buff, "pa") == 0)
				pa_checker(&list_a, &list_b);
			if (ft_strcmp(buff, "pb") == 0)
				pb_checker(&list_a, &list_b);
			if (ft_strcmp(buff, "ra") == 0)
				ra_checker(&list_a);
			if (ft_strcmp(buff, "rb") == 0)
				rb_checker(&list_b);
			if (ft_strcmp(buff, "rr") == 0)
				rr_checker(&list_a, &list_b);
			if (ft_strcmp(buff, "rra") == 0)
				rra_checker(&list_a);
			if (ft_strcmp(buff, "rrb") == 0)
				rrb_checker(&list_b);
			if (ft_strcmp(buff, "rrr") == 0)
				rrr_checker(&list_a, &list_b);
			free(buff);
		}
		if (checking_stack_sorted(list_a, min, n) == 1)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	return (0);
}
