/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 20:06:44 by semen             #+#    #+#             */
/*   Updated: 2020/09/04 01:22:05 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_num *list, t_key *bonus)
{
	int tmp_current;
	int tmp_next;
	int n;

	n = count_list(list);
	if (n > 1)
	{
		tmp_current = list->n;
		list = list->next;
		tmp_next = list->n;
		list->n = tmp_current;
		list = list->prev;
		list->n = tmp_next;
		if (bonus->print == 1)
			ft_printf("sa\n");
	}
}
