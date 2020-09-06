/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:09:54 by calpha            #+#    #+#             */
/*   Updated: 2020/09/06 13:31:39 by oem              ###   ########.fr       */
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
	tmp->print = 1;
	*bonus = tmp;
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
	free(av[0]);
	free(av);
	return (argk);
}

static void clear_array(int ac, char **ar)
{
	int i;

	i = 0;
	while (i < ac)
	{
		free(ar[i]);
		i++;
	}
	free(ar);
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

static void	when_one_parameter(int ac, char **ar)
{
	if (ac == 0)
	{
		printf("Enter more than one parameter\n");
		exit (0);
	}
	if (ac == 1)
	{
		clear_array(ac, ar);
		exit (0);
	}
}

static void	when_one_parameter_key(int ac, char **ar, t_key *bonus)
{
	if (ac == 0)
	{
		printf("Enter more than one parameter\n");
		free(bonus);
		exit (0);
	}
	if (ac == 1)
	{
		clear_array(ac, ar);
		free(bonus);
		exit (0);
	}
}

int			main(int ac, char *av[])
{
	t_num *list_a;
	t_num *list_b;
	t_key *bonus;
	char **ar;
	// char **af;
	int n;
	int min;

	list_b = NULL;
	ar = parser(ac, av, &ac);
	if (ac == 0 || ac == 1)
		when_one_parameter(ac, ar);
	create_list_bonus(&bonus);

	// int a = 0;
	// while(a < ac)
	// {
	// 	printf("ar[%d] = %s\n", a, ar[a]);
	// 	a++;
	// }
	// printf("ac = %d\n", ac);

	if (ft_strcmp(ar[0], "-v") == 0)
	{
		ar = key_function(ac, ar, &ac);
		bonus->key = 1;
	}

	// a = 0;
	// while(a < ac)
	// {
	// 	printf("af[%d] = %s\n", a, af[a]);
	// 	a++;
	// }
	// printf("ac = %d\n", ac);
	if (ft_strcmp(ar[0], "-c") == 0)
	{
		ar = key_function(ac, ar, &ac);
		bonus->key = 2;
	}
	if (validation(ac, ar) == 0)
	{
		ft_putstr("Error\n");
		clear_array(ac, ar);
		free(bonus);
		exit (0);
	}
	if (ac == 0 || ac == 1)
		when_one_parameter_key(ac, ar, bonus);
	if (!(list_a = create_stack_a(ac, ar)))
		return (0);
	clear_array(ac, ar);
	n = count_list(list_a);
	min = find_min_number(list_a);
	if (checking_stack_sorted(list_a, min, n) == 1)
	{
		free_list(list_a, bonus);
		exit (0);
	}
	if (n <= 10)
		sort_ten_num(list_a, list_b, bonus);
	else
		timsort(list_a, list_b, bonus);
	free_list(list_a, bonus);
	return (0);
}
