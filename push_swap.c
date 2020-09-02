/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:09:54 by calpha            #+#    #+#             */
/*   Updated: 2020/09/02 12:21:58 by oem              ###   ########.fr       */
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

char **key_function(int ac, char *av[], int *ret)
{
	char **argk;
	int i;
	int j;

	i = 0;
	j = 1;
	if (!(argk = (char **)malloc((--ac) * sizeof(char *))))
		return (0);
	while (i < ac)
	{
		argk[i] = av[j];
		i++;
		j++;
	}
	*ret = ac;
	return (argk);
}

int			main(int ac, char *av[])
{
	t_number *list_a;
	t_number *list_b;
	int n;
	int min;
	int key;

	list_b = NULL;
	if (ac == 1 || ac == 2)
		when_one_parameter(ac, av);
	// printf("ac = %d\n", ac);
	av = parser(ac, av, &ac);
	if (ft_strcmp(av[0], "-v") == 0)
	{
		av = key_function(ac, av, &ac);
		key = 1;
	}
	if (validation(ac, av) == 0)
	{
		ft_putstr("Error\n");
		exit (0);
	}
	if (ac == 1)
		exit (0);

	// printf("a = %d\n", a);
	// int a = 0;
	// while (a < ac)
	// {
	// 	printf("arg[%d] = %s\n", a, av[a]);
	// 	a++;
	// }
	// printf("ac = %d\n", ac);
	// usleep(3000000);

	list_a = create_stack_a(ac, av);

	n = count_list(list_a);

	min = find_min_number(list_a);

	if (checking_stack_sorted(list_a, min, n) == 1)
		exit (0);

	if (key == 0)
	{
		if (n <= 10)
		sorting_upten_num(list_a, list_b);
		else
		timsort(list_a, list_b);
	}
	if (key == 1)
	{
		if (n <= 10)
		sorting_upten_num_kv(list_a, list_b);
		else
		timsort_kv(list_a, list_b);
	}
	return (0);
}
