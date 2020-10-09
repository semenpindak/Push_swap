/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_two.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 10:05:43 by oem               #+#    #+#             */
/*   Updated: 2020/09/05 10:09:22 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_two(t_num **list, t_key *bonus)
{
	int tmp_current;
	int tmp_next;
	int n;

	n = count_list_two(list);
	if (n > 1)
	{
		tmp_current = (*list)->n;
		(*list) = (*list)->next;
		tmp_next = (*list)->n;
		(*list)->n = tmp_current;
		(*list) = (*list)->prev;
		(*list)->n = tmp_next;
		if (bonus->print == 1)
			ft_printf("sa\n");
	}
}
