/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semen <semen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 16:47:17 by semen             #+#    #+#             */
/*   Updated: 2020/04/11 22:06:13 by semen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	counting_number_nodes(t_number *list_a)
{
	int n;
	int m;

	n = 0;
	m = list_a->n;
	n++;
	if(list_a->next)
		list_a = list_a->next;
	else
		return(1);
	while (list_a)
	{
		if (list_a->n != m)
			list_a = list_a->next;
		else
			break;
		n++;
	}
	return(n);
}

static int	find(t_number *list_a, int n, int x)
{
	t_number *head;
	int min;
	int m;
	int lim;

	head = list_a;
	min = list_a->n;
	m = n;
	while(m)
	{
		list_a = list_a->next;
		if (list_a->n < min)
			min = list_a->n;
		m--;
	}
	while(x)
	{
		m = n;
		lim = min;
		min = 2147483647;
		list_a = head;
		while (m)
		{
			if (list_a->n > lim && list_a->n < min)
				min = list_a->n;
			list_a = list_a->next;
			m--;
		}
		x--;
	}
	// printf("%d\n", min);
	return (min);
}

int			find_median_number(t_number *list_a)
{
	int n;
	int x;
	double m;
	int ret;

	n = counting_number_nodes(list_a);
	m = (double)n / 2;
	x = (m < (n / 2 + 1) && m > (n / 2)) ? n / 2 + 1 : n / 2;
	ret = find(list_a, n, x);
	// printf("%d", n);
	// printf("%f", m);
	return (ret);
}
