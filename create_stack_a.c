/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 20:13:26 by semen             #+#    #+#             */
/*   Updated: 2020/08/24 19:19:24 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_number	*get_last(t_number *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

static void		push_ring(t_number *head, int j, char *av[])
{
	t_number	*last;
	t_number	*tmp;

	last = get_last(head);
	tmp = (t_number *)malloc(sizeof(t_number));
	tmp->n = ft_atoi(av[j]);
	tmp->status = 0;
	tmp->next = head;
	tmp->prev = last;
	last->next = tmp;
	head->prev = tmp;
}

static void		push_back(t_number *head, int j, char *av[])
{
	t_number	*last;
	t_number	*tmp;

	last = get_last(head);
	tmp = (t_number *)malloc(sizeof(t_number));
	tmp->n = ft_atoi(av[j]);
	tmp->status = 0;
	tmp->next = NULL;
	tmp->prev = last;
	last->next = tmp;
}

static void		push(t_number **head, int j, char *av[])
{
	t_number	*tmp;

	tmp = (t_number *)malloc(sizeof(t_number));
	tmp->n = ft_atoi(av[j]);
	tmp->status = 0;
	tmp->next = NULL;
	tmp->prev = NULL;
	*head = tmp;
}

t_number		*create_stack_a(int ac, char *av[])
{
	int			j;
	t_number	*list;

	j = 1;
	while (j < ac)
	{
		if (j == 1)
			push(&list, j, av);
		if (j != 1 && j != ac - 1)
			push_back(list, j, av);
		if ((j == ac - 1) && j > 1)
			push_ring(list, j, av);
		j++;
	}
	return (list);
}
