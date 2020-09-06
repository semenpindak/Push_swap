/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 20:13:26 by semen             #+#    #+#             */
/*   Updated: 2020/09/04 17:44:55 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_num	*get_last(t_num *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

static void push_ring(t_num *head, int j, char *av[])
{
	t_num	*last;
	t_num	*tmp;

	last = get_last(head);
	tmp = (t_num *)malloc(sizeof(t_num));
	tmp->n = ft_atoi(av[j]);
	tmp->status = 0;
	tmp->next = head;
	tmp->prev = last;
	last->next = tmp;
	head->prev = tmp;
}

static void push_back(t_num *head, int j, char *av[])
{
	t_num	*last;
	t_num	*tmp;

	last = get_last(head);
	tmp = (t_num *)malloc(sizeof(t_num));
	tmp->n = ft_atoi(av[j]);
	tmp->status = 0;
	tmp->next = NULL;
	tmp->prev = last;
	last->next = tmp;
}

static void push(t_num **head, int j, char *av[])
{
	t_num	*tmp;

	tmp = (t_num *)malloc(sizeof(t_num));
	tmp->n = ft_atoi(av[j]);
	tmp->status = 0;
	tmp->next = NULL;
	tmp->prev = NULL;
	*head = tmp;
}

t_num		*create_stack_a(int ac, char *av[])
{
	int		j;
	t_num	*list;

	j = 0;
	while (j < ac)
	{
		if (j == 0)
			push(&list, j, av);
		if (j != 0 && j != ac - 1)
			push_back(list, j, av);
		if ((j == ac - 1) && j > 0)
			push_ring(list, j, av);
		j++;
	}
	return (list);
}
