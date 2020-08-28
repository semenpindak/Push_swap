/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:09:54 by calpha            #+#    #+#             */
/*   Updated: 2020/08/28 18:19:23 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int	find_min_number(t_number *list_b)
// {
// 	int min;
// 	int n;

// 	min = list_b->n;
// 	n = list_b->n;
// 	while(list_b)
// 	{
// 		list_b = list_b->next;
// 		if (list_b->n < min)
// 			min = list_b->n;
// 		if (n == list_b->n)
// 			break;
// 	}
// 	return (min);
// }

// static int	checking_stack_sorted(t_number *list_a, int min, int n)
// {
// 	int current;

// 	while (list_a)
// 	{
// 		if (list_a->n == min)
// 			break;
// 		list_a = list_a->next;
// 	};
// 	n--;
// 	while (list_a)
// 	{
// 		current = list_a->n;
// 		list_a = list_a->next;
// 		if (current < list_a->n)
// 		{
// 			n--;
// 			if (n == 0)
// 				return (1);
// 		}
// 		else
// 			return (0);
// 	}
// 	return (-1);
// }

static void	when_parameters_one(void)
{
		printf("Enter more than one parameter\n");
		exit (0);
}

static char **parser(int ac, char *av[], int *ret)
{
	char ***arg = NULL;
	int i;
	int j;

	i = 0;
	j = 1;
	arg = (char ***)malloc((ac) * sizeof(char **));
	arg[ac - 1] = NULL;

	printf("ac = %d\n", ac);

	while (j < ac)
	{
		printf("j = %d < ac = %d\n", j, ac);
		arg[i] = ft_strsplit(av[j], 32);
		i++;
		j++;
		printf("j = %d < ac = %d\n", j, ac);
	}


	printf("i = %d, j = %d\n", i, j);
	i = 0;
	j = 0;
	int k = 0;


	printf("ac = %d\n", ac);
	while (arg[i] != NULL)
	{
		j = 0;
		while(arg[i][j] != NULL)
			j++;
		i++;
		k += j;
		printf("i = %d, k = %d\n", i, k);
	}


	char **argw;
	argw = (char **)malloc((k) * sizeof(char *));


	i = 0;
	j = 0;
	int a = 0;
	while (arg[i] != NULL)
	{
		j = 0;
		while(arg[i][j] != NULL)
		{
			argw[a] = arg[i][j];
			j++;
			a++;
		}
		i++;
	}

	// printf("a = %d\n", a);
	// a = 0;
	// while (a < k)
	// {
	// 	printf("arg[%d] = %s\n", a, argw[a]);
	// 	a++;

	// }

	// printf("k = %d\n", k);

	*ret = k;
	printf("*ret = %d\n", *ret);
	return (argw);
}




int			main(int ac, char *av[])
{
	// char **arg = NULL;
	// t_number *list_a;
	// t_number *list_b;
	// int n;
	// int min;
	// int i;
	// int j;

	// i = 0;
	// j = 1;
	// list_b = NULL;
	if (ac == 1)
		when_parameters_one();

	printf("ac = %d\n", ac);
	av = parser(ac, av, &ac);
	// ac++;

	// printf("a = %d\n", a);
	int a = 0;
	while (a < ac)
	{
		printf("arg[%d] = %s\n", a, av[a]);
		a++;
	}
	printf("ac = %d\n", ac);
	usleep(3000000);

	if (validation(ac, av) == 0)
	{
		ft_putstr("Error\n");
		exit (0);
	}
	// list_a = create_stack_a(ac, av);


	// n = count_list(list_a);
	// min = find_min_number(list_a);
	// if (checking_stack_sorted(list_a, min, n) == 1)
	// 	exit (0);
	// if (n <= 10)
	// 	sorting_upten_num(list_a, list_b);
	// else
	// 	timsort(list_a, list_b);
	return (0);
}
