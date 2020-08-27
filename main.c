/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:09:54 by calpha            #+#    #+#             */
/*   Updated: 2020/08/27 22:08:24 by calpha           ###   ########.fr       */
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

static void	when_parameters_one(void)
{
		printf("Enter more than one parameter\n");
		exit (0);
}

int			main(int ac, char *av[])
{
	char ***arg = NULL;
	t_number *list_a;
	t_number *list_b;
	int n;
	int min;
	int i;
	int j;

	i = 0;
	j = 1;
	list_b = NULL;
	if (ac == 1)
		when_parameters_one();

	arg = (char ***)malloc((ac - 1) * sizeof(char **));
	arg[ac] = NULL;
	while (arg[i] != NULL)
	{
		i++;
		// if (arg[i] == NULL)
		// 	break;
	}
	// printf("%s\n", arg[ac]);
	printf("%d\n", i);
	i = 0;
	while (j <= ac)
	{
		arg[i] = ft_strsplit(av[j], 32);
		i++;
		j++;
	}

	// i = 0;
	// while (i <= ac)
	// {
	// 	j = 0;
	// 	while (j <= ft_strlen(arg[i][j]))
	// 	{
	// 		printf("arg[j] = %s\n", arg[i][j]);
	// 		j++;
	// 	}
	// 	i++;
	// }

	j = 1;
	// printf("ac = %d\n", ac);
	printf("arg[j] = %s\n", arg[0][0]);
	printf("arg[j] = %s\n", arg[0][1]);
	printf("arg[j] = %s\n", arg[0][2]);

	j = 2;
	// arg = ft_strsplit(av[j], 32);
	printf("arg[j] = %s\n", arg[1][0]);

	j = 3;
	// arg = ft_strsplit(av[j], 32);
	printf("arg[j] = %s\n", arg[2][0]);
	printf("arg[j] = %s\n", arg[2][1]);
	printf("arg[j] = %s\n", arg[2][2]);


	// while (j--)
	// {
	// 	printf("arg[j] %s\n", arg[j]);
	// 	j++;
	// }

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


	if (n <= 10)
		sorting_upten_num(list_a, list_b);
	else
		timsort(list_a, list_b);
	return (0);
}
