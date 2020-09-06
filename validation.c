/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 14:06:33 by semen             #+#    #+#             */
/*   Updated: 2020/09/05 23:49:23 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_arg_number(int ac, char *av[])
{
	int n;
	int m;

	n = 0;
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

static int	check_length_min_max(char *av[], int n)
{
	int i;
	int j;
	char *check_int;

	i = 0;
	j = 0;
	if(av[n][0] == '-')
	{
		i++;
		check_int = "2147483648";
	}
	else
		check_int = "2147483647";
	while (av[n][i] != '\0')
	{
		if (av[n][i] > check_int[j])
		{
			free(check_int);
			return (0);
		}
		i++;
		j++;
	}
	free(check_int);
	return (1);
}

static int	check_min_max_number(int ac, char *av[])
{
	int n;

	n = 0;
	while (n < ac)
	{
		if (((ft_strlen(av[n]) > 10) && av[n][0] != '-') || ((ft_strlen(av[n]) > 11) && av[n][0] == '-'))
			return (0);
		if (((ft_strlen(av[n]) == 10) && av[n][0] != '-') || ((ft_strlen(av[n]) == 11) && av[n][0] == '-'))
		{
			if (check_length_min_max(av, n) == 0)
				return (0);
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
	if (!(ar_check = (int *)malloc(sizeof(int) * ac)))
		return (0);
	while (i < ac)
	{
		ar_check[i] = ft_atoi(av[i]);
		i++;
	}
	i = 0;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
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
