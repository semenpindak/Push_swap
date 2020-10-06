/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 12:07:42 by oem               #+#    #+#             */
/*   Updated: 2020/10/06 19:14:01 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_number(t_num *list_b)
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

static int	checking_stack_sorted(t_num *list_a, int min, int n)
{
	int current;

	if (count_list(list_a) != n)
		return (0);

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

static	void create_list_bonus(t_key **bonus)
{
	t_key *tmp;

	tmp = (t_key *)malloc(sizeof(t_key));
	tmp->key = 0;
	tmp->i = 0;
	tmp->print = 0;
	*bonus = tmp;
}

void reading_commands(t_num **list_a, t_num **list_b, t_key *bonus)
{
	char *buff;

	while (get_next_line(0, &buff) > 0)
	{
		if (ft_strcmp(buff, "sa") == 0)
			sa_two(list_a, bonus);
		if (ft_strcmp(buff, "pa") == 0)
			pa(&list_a, &list_b, bonus);
		if (ft_strcmp(buff, "pb") == 0)
			pb(&list_a, &list_b, bonus);
		if (ft_strcmp(buff, "ra") == 0)
			ra(&list_a, bonus);
		if (ft_strcmp(buff, "rb") == 0)
			rb(&list_b, bonus);
		if (ft_strcmp(buff, "rr") == 0)
			rr(&list_a, &list_b, bonus);
		if (ft_strcmp(buff, "rra") == 0)
			rra(&list_a, bonus);
		if (ft_strcmp(buff, "rrb") == 0)
			rrb(&list_b, bonus);
		if (ft_strcmp(buff, "rrr") == 0)
			rrr(&list_a, &list_b, bonus);
		free(buff);
	}
}

static void	when_one_parameter(int ac, char **ar)
{
	free_array(ac, ar);
	exit (0);
}

static void	free_list(t_num *list_a, t_key *bonus)
{
	int n;

	n = count_list(list_a);
	n--;
	while (n)
	{
		free(list_a->prev);
		if (n == 1)
			break ;
		list_a = list_a->next;
		n--;
	}
	free(list_a);
	free(bonus);
}

int	main(int ac, char *av[])
{
	t_num *list_a;
	t_num *list_b;
	t_key *bonus;
	char **ar;
	int n;
	int min;

	list_b = NULL;
	ar = parser(ac, av, &ac);

	// int a = 0;
	// while(a < ac)
	// {
	// 	printf("av[%d] = %s\n", a, ar[a]);
	// 	a++;
	// }
	// printf("ac = %d\n", ac);

	if (ac == 0 || ac == 1)
		when_one_parameter(ac, ar);

	if (validation(ac, ar) == 0)
	{
		ft_putstr("Error\n");
		free_array(ac, ar);
		exit (0);
	}
	create_list_bonus(&bonus);
	list_a = create_stack_a(ac, ar);
	free_array(ac, ar);
	n = count_list(list_a);
	min = find_min_number(list_a);
	if (ac > 1)
	{
		reading_commands(&list_a, &list_b, bonus);
		if (checking_stack_sorted(list_a, min, n) == 1)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	free_list(list_a, bonus);
	return (0);
}
