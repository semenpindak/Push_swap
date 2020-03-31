/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semen <semen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 14:06:33 by semen             #+#    #+#             */
/*   Updated: 2020/03/31 14:22:00 by semen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_arg_number(int ac, char *av[])
{
	int n;
	int m;

	n = 1;
	while (n < ac)
	{
		m = 0;
		while (av[n][m] != '\0')
		{
			if ((av[n][m] < '-' || av[n][m] > '-') && (av[n][m] < '0' || av[n][m] > '9'))
				return (0);
			m++;
		}
		n++;
	}
	return (1);
}

static int	check_min_max_number(int ac, char *av[])
{
	int n;
	int i;
	int j;
	char *check_int;

	n = 1;
	i = 0;
	j = 0;
	check_int = "2147483647";
	while (n < ac)
	{
		if (((ft_strlen(av[n]) > 10) && av[n][0] != '-') || ((ft_strlen(av[n]) > 11) && av[n][0] == '-'))
			return (0);
		if (((ft_strlen(av[n]) == 10) && av[n][0] != '-') || ((ft_strlen(av[n]) == 11) && av[n][0] == '-'))
		{
			if(av[n][0] == '-')
				i++;
			while (av[n][i] != '\0')
			{
				if (av[n][i] > check_int[j])
					return (0);
				i++;
				j++;
			}
		}
		n++;
	}
	return (1);
}

static int	check_duplicates(int ac, char *av[])
{
	int i;
	int j;
	int *ar_check;

	i = 0;
	j = 1;
	if (!(ar_check = (int *)malloc(sizeof(int) * (ac - 1))))
		return (0);
	while (j < ac)
	{
		ar_check[i] = ft_atoi(av[j]);
		j++;
		i++;
	}
	i = 0;
	while (i < ac - 1)
	{
		j = i + 1;
		while (j < ac - 1)
		{
			if (ar_check[i] == ar_check[j])
			{
				free(ar_check);
				return (0);
			}
			j++;
		}
		i++;
	}
	free(ar_check);
	return (1);
}

int			validation(int ac, char *av[])
{
	if (check_arg_number(ac, av) == 0)
		return (0);
	if (check_min_max_number(ac, av) == 0)
		return (0);
	if (check_duplicates(ac, av) == 0)
		return (0);
	return (1);
}
