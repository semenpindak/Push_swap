/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 20:06:44 by semen             #+#    #+#             */
/*   Updated: 2020/09/04 01:06:52 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_num *list)
{
	int tmp_current;
	int tmp_next;

	if (list)
	{
		tmp_current = list->n;
		list = list->next;
		tmp_next = list->n;
		list->n = tmp_current;
		list = list->prev;
		list->n = tmp_next;
		ft_printf("sb\n");
	}
}
